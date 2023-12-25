// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 6: Game of Life
// Purpose: Write a program that simulates the playing or animation of Conway's Game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells). (Functions file)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "lifefunc.h"

// Function to initialize the cell array into blank spaces
char cell_init() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cell[i][j] = ' ';
		}
	}
	
	return cell[SIZE][SIZE];
}

// Function to initialize the new cell array into blank spaces
char new_cell_init() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			new_cell[i][j] = ' ';
		}
	}

	return new_cell[SIZE][SIZE];
}

// Function to display the walls of the board 
void display(char cell[SIZE][SIZE]) {

	for (int i = 0; i < SIZE + 2; i++) {
		if (i == 0) {
			printf(" ");
		}
		else if (i > 0 && i < SIZE + 1) {
			printf("-");
		}
		else if (i == SIZE + 1) {
			printf(" ");
		}
	}
	printf("\n");
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE + 2; j++) {
			if (j == 0) {
				printf("|");
			}
			else if (j > 0 && j < SIZE + 1) {
				printf("%c", cell[i][j - 1]);
			}
			else if (j == SIZE + 1) {
				printf("|");
			}
		}
		printf("\n");
	}

	for (int i = 0; i < SIZE + 2; i++) {
		if (i == 0) {
			printf(" ");
		}
		else if (i > 0 && i < SIZE + 1) {
			printf("-");
		}
		else if (i == SIZE + 1) {
			printf(" ");
		}
	}
	printf("\n");
}

// Function to the rules of the game
char rules (char cell[SIZE][SIZE], char new_cell[SIZE][SIZE]) {

	// nested for loops to check if 1) a dead cell with exactly three neighbors becomes live and 2) only a live cell with two or three neighbors survives, all others die
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (cell[i][j] == ' ') {
				int count_dead = 0;
				if (cell[i - 1][j - 1] == 'X') {
					count_dead++;
				}
				if (cell[i - 1][j] == 'X') {
					count_dead++;
				}
				if (cell[i - 1][j + 1] == 'X') {
					count_dead++;				
				}					
				if (cell[i][j - 1] == 'X') {
					count_dead++;
				}
				if (cell[i][j + 1] == 'X') {
					count_dead++;
				}
				if (cell[i + 1][j - 1] == 'X') {
					count_dead++;
				}
				if (cell[i + 1][j] == 'X') {
					count_dead++;
				}
				if (cell[i + 1][j + 1] == 'X') {
					count_dead++;
				}
				if (count_dead == 3) {
					new_cell[i][j] = 'X';
				}
			}
			else if (cell[i][j] == 'X') {
				int count_live = 0;
				if (cell[i - 1][j - 1] == 'X') {
					count_live++;
				}
				if (cell[i - 1][j] == 'X') {
					count_live++;
				}
				if (cell[i - 1][j + 1] == 'X') {
					count_live++;
				}
				if (cell[i][j - 1] == 'X') {
					count_live++;
				}
				if (cell[i][j + 1] == 'X') {
					count_live++;
				}
				if (cell[i + 1][j - 1] == 'X') {
					count_live++;
				}
				if (cell[i + 1][j] == 'X') {
					count_live++;
				}
				if (cell[i + 1][j + 1] == 'X') {
					count_live++;
				}
					if (count_live == 2 || count_live == 3) {
						new_cell[i][j] = 'X';
					}
					else {
						new_cell[i][j] = ' ';
					}
			}
		}
	}

	// for loop to update the current board by making it equal to the temporary board
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cell[i][j] = new_cell[i][j];
		}
	}

	return cell[SIZE][SIZE];
	return new_cell[SIZE][SIZE];

}

// Function to display an appropriate error message in the case the user enters an invalid point
void error_message(int rows, int columns)
{
	if (rows < 0 || rows > SIZE - 1 || columns < 0 || columns > SIZE - 1) {
		printf("Invalid point!");
		printf("\n");
	}
}

// Function to run the game in interactive mode according to the command inputs 
char game(char cell[SIZE][SIZE], char new_cell[SIZE][SIZE], char prompt, char rows, char columns) {
	
	if (prompt == 'a') {
		cell[rows][columns] = 'X';
		error_message(rows, columns);
		display(cell);
	}
	else if (prompt == 'r') {
		cell[rows][columns] = ' ';
		error_message(rows, columns);
		display(cell);
	}
	else if (prompt == 'n') {
		rules(cell, new_cell);
		display(cell);
	}	
	else if (prompt == 'p') {
		while (1) {		
			rules(cell, new_cell);
			system("clear");
			display(cell);
			usleep(100000);

		}
	}
	else {
		printf("unknown command.");
		printf("\n");
	}	
	
	return cell[SIZE][SIZE];
	return new_cell[SIZE][SIZE];

}


