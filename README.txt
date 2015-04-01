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

Compilation

To compile this program, point your terminal at the directory containing the src, include and bin folders and Makefile.
Type make into the command line and the program will compile.

Running

After compiling, stay in the same directory and type ./bin/runMe into the terminal.

Operation

Two players enter their names and play the game of Obstruction.
The players alternate selecting boxes in a 6x6 grid, when a box is selected, the box and all adjacent boxes are highlighted, blocking
them off from being selected again.
The game continues until the board is full, the player to last select a box is the winner.

Known limitations

The game can only be played with 2 human players, there is no built in AI.
The game will not keep score of wins by each player.

Extras

The game uses a solid blue border, I believe this looks better than a border made up of characters.
The game places coloured pieces when a player selects a box.  This is to differentiate between who has played and looks good.

