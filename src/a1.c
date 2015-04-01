/***********************************************************************************************
Student Name: Benjamin Davey    Student Number: 0885413 
Date: Friday, January 16, 2015  Course Name: CIS2500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
***********************************************************************************************/

#include "a1.h"

int main(void)
{
    char playerOne[100];
    char playerTwo[100] = "Computer";
    int turn = 1;
	int newTurn = 1;
	char userInput = 'b';
	int check = 0;
	int y = 0;
	int x = 0;

	printf("Welcome to Obstruction!\n");
	printf("To play, players take turns selecting boxes on a 6x6 grid.\n");
	printf("The box selected and all adjacent boxes are then blocked off\n");
	printf("The last person to place a marker is the winner.\n");
	printf("Please enter Player One's name  ");
	scanf("%s", playerOne);
	printf("Please enter Player Two's name  ");
	scanf("%s", playerTwo);

    initscr();
    noecho();
    cbreak();
    drawGrid(6, 6);
    move(1,1);
    refresh();
    printToScreen("Player 1 go!");

/*This loop takes user input and sends it to a function to handle.  It then takes the return
value from that function to check if the player has placed a marker, if so, the next player 
is up.  It then uses a function to check if the board is full.  The loop ends (ending the game)
when the user selects q to quit or the board is full.*/
    do 
    {
    	userInput = getch();
    	clearScreen();
    	newTurn = moveCursor(userInput, turn);
    	turn = newTurn;
    	getyx(stdscr, y, x);
    	check = checkEnd(y, x);
    } while (userInput != 'q' && check > 0);

/*This if statement check if the above while loop ended due to players selecting to quit or
the board being full, if the latter is true it congratulates the winner.*/
    if (userInput != 'q')
    {
    	start_color();
        init_pair(1, 7, 0);
        attron(COLOR_PAIR (1));
	    getyx(stdscr, y, x);
	    clearScreen();
    	if (turn == 1)
	    {
		    mvwprintw (stdscr, 8, 0, "%s wins!, press any key to quit", playerTwo);
	    }
	    else
	    {
		    mvwprintw (stdscr, 8, 0, "%s wins! press any key to quit", playerOne);
	    }
	    move(1,1);
	    getch();
    }
    refresh();
    endwin();
    return 0;
}

/*This function checks every space on the grid, if the space is empty it adds 1 to a variable, the
variable is returned and evaluated in main to see if the game is over.  It takes in x and y so that 
the cursor can be moved to original location at end of function.*/
int checkEnd(int y, int x)
{
	int i = 1;
	int j = 1;
	char current = ' ';
    int test = 0;
    current = mvinch(i,j);
	for (i = 1; i<7; i++)
    {
		for (j = 1; j<7; j++)
	    {
			current = mvinch(i,j);
            if (current == ' ')
            {
            	test++;
            }
		}
	}
	move(y,x);
	return test; 
}

/*This function is called from the printSurroiunding function.  It x and y to know location, checks to 
see if the current block is empty and prints a # to block off the block.*/
void checkLocation(int y, int x)
{
	char current = ' ';
	move (y,x);
	current = mvinch(y, x);
	if (current == ' ') 
    {
		printw("#");
	}
}

/*This function takes in nothing, returns nothing.  It moves to the location that messages are printed and
prints a line of spaces to clear the message then returns the cursor to the location it was before.*/
void clearScreen()
{
	int y = 0;
	int x = 0;

    start_color();
    init_pair(1, 7, 0);
    attron(COLOR_PAIR (1));
	getyx(stdscr, y, x);
	mvwprintw (stdscr, 8, 0, "                                                                              ");
    move(y,x);
    refresh();
}

/*This function takes in a variable for height and width and prints a grid of that size to the screen.
It does so with blue foreground and background so that the grid looks like a solid border.  The function
returns nothing.*/
void drawGrid(int height, int width)
{
	int i = 0;
    width = width + 1;
    height = height + 2;
    
    start_color();
    init_pair(2, 4, 4);
    attron(COLOR_PAIR (2));
    for (i=0; i<width; i++)
    {
        move(0, i);
        printw("*"); 
    }
    for (i=0; i<width; i++)
    {
        move(7, i);
        printw("*"); 
    }
    for (i=0; i<height; i++)
    {
        move(i, 0);
        printw("*"); 
    }
	for (i=0; i<height; i++)
    {
        move(i, 7);
        printw("*"); 
    }
}

/*This function takes in the user input, if it is a direction key (ijkl) it moves the cursor in that direction
if it is q it does nothing, if it is s it calls another function to */
int moveCursor(char input, int playerTurn)
{
	int x = 0;
	int y = 0;
	int yStart = 0;
	int xStart= 0;
	char next = '*';
	char current = ' ';

	getyx(stdscr, yStart, xStart);
	getyx(stdscr, y, x);
	switch (input)
    {
		case UP:
		    y--;
		    break;
		case DOWN:
		    y++;
			break;
		case LEFT:
		    x--;
			break;
		case RIGHT:
		    x++;
			break;
		case SELECT:
		    current = mvinch(y, x);
		    if (current == ' ')
		    {
		    	placeMarker(playerTurn);
		    	if (playerTurn == 1)
		        {
		    		playerTurn = 2;
		    	}
		    	else
		        {
		    		playerTurn = 1;
		    	}
		    }
		    else
		    {
		    	printToScreen("You cannot place marker in an occupied space!");
		    }
		    break;
		default:
			printToScreen("Please only use i j k l for movement, s to select or q to quit\n");

	}
	move(y,x);
	next = mvinch(y, x);
	if (next == '*')
    {
		printToScreen("Please stay in the playing area\n");
		move(yStart, xStart);
	}
	refresh();
	return playerTurn;
}

/*This function takes in an integer that indicates which player's turn it is.  The function 
print the character that cooresponds to the player whos turn it is.  It calls the printSurrounding function 
to print all the adjacent squares.  This function returns nothing.*/
void placeMarker(int playerTurn)
{
	int y = 0;
	int x = 0;
    getyx(stdscr, y, x);
    if (playerTurn == 1)
    {
    	start_color();
        init_pair(3, 1, 0);
        attron(COLOR_PAIR (3));
    	mvwprintw(stdscr, y, x, "O");
    	refresh();
    	printSurrounding(y, x);
    	refresh();
    }
    if (playerTurn == 2)
    {
    	start_color();
        init_pair(4, 2, 0);
        attron(COLOR_PAIR (4));
    	mvwprintw(stdscr, y, x, "X");
    	refresh();
    	printSurrounding(y, x);
    	refresh();
    }
    
}

/*This function is called after a player selects to place a marker.  It moves to all
adjacent places and calls the checkLocation function which checks square and if it is empty, 
blocks off the place.  This function takes in y and x so it knows where to start moving to adjacent
blocks.*/
void printSurrounding(int y, int x)
{
	start_color();
    init_pair(1, 7, 0);
    attron(COLOR_PAIR (1));
	y++;
	checkLocation(y, x);
	y = y-2;
    checkLocation(y,x);
    y++;
	x++;
	checkLocation(y,x);
	x = x-2;
    checkLocation(y,x);
    y--;
    checkLocation(y,x);
    y=y+2;
    checkLocation(y,x);
    x=x+2;
    checkLocation(y,x);
    y=y-2;
    checkLocation(y,x);
	refresh();

}

/*This function takes in a message and prints the message to the sreen. It returns nothing.*/
void printToScreen(char *message)
{
	int y = 0;
	int x = 0;
    
    start_color();
    init_pair(1, 7, 0);
    attron(COLOR_PAIR (1));
	getyx(stdscr, y, x);
	clearScreen();
	mvwprintw (stdscr, 8, 0, message);
    move(y,x);
    refresh();
}
