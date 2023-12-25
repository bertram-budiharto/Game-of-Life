// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 6: Game of Life
// Purpose: Write a program that simulates the playing or animation of Conway's Game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells). (Header file) 

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define SIZE 40

char cell[SIZE][SIZE];
char new_cell[SIZE][SIZE];

// Function to display the walls of the board
char cell_init();

// Function to the rules of the game
char new_cell_init();

// Function to display the walls of the board 
void display(char [SIZE][SIZE]);

// Function to the rules of the game 
char rules(char [SIZE][SIZE], char [SIZE][SIZE]);

// Function to display an appropriate error message in the case the user enters an invalid point
void error_message(int rows, int columns);

// Function to run the game in interactive mode according to the command inputs 
char game(char [SIZE][SIZE], char [SIZE][SIZE], char prompt, char rows, char columns);

