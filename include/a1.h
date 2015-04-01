#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define UP 'i'
#define LEFT 'j'
#define DOWN 'k'
#define RIGHT 'l'
#define SELECT 's'
#define QUIT 'q'

int checkEnd(int y, int x);
void checkLocation(int y, int x);
void clearScreen();
void drawGrid(int height, int width);
int moveCursor(char input, int playerTurn);
void placeMarker(int playerTurn);
void printSurrounding(int y, int x);
void printToScreen(char *message);