// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 6: Game of Life
// Purpose: Write a program that simulates the playing or animation of Conway's Game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells). (Main Driver)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "lifefunc.h"

int main(int argc, char* argv[]) {
	
	char command[100]; // establishes the command array for user input 

	char prompt;
	int rows, columns;
	
	cell_init(); // calling the cell initialization function 
	new_cell_init(); // calling the new cell initialization function

	// if statements for different scenarios of command line argument inputs
	if (argc == 1) {
		display(cell); // calling the display function to create the fixed walls of the board
		while (1) {
			printf("COMMAND: ");
			fgets(command, 100, stdin); // store the user inputs to the command array
			sscanf(command, "%c %d %d", &prompt, &rows, &columns); // parse the user inputs into prompt, rows, columns
			if (prompt != 'q') {
				game(cell, new_cell, prompt, rows, columns); // calling the game function to apply the rules of the game
			}
			else {
				printf("Goodbye!");
				printf("\n");
				break;
			}
		}
	}
	else if (argc == 2) {
		FILE* file = fopen(argv[1], "r"); 
		if (file == NULL) {
			printf("Inappropiate file!");
			printf("\n");
		}
		else {
			while (1) {
				fgets(command, 100, file); // store the command in the file line by line to the command array
				sscanf(command, "%c %d %d", &prompt, &rows, &columns); // parse the command into prompt, rows, columns
				game(cell, new_cell, prompt, rows, columns); // calling the game function to apply the rules of the game
			}
		}
	}
	else {
		printf("Too many inputs!");
		printf("\n");
	}

	return 0;

}


