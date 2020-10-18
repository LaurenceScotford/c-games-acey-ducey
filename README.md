# c-games-acey-ducey
A conversion to C of the *Acey Ducey* game from David Ahl's book *BASIC Computer Games*.
Acey Ducey is a simple card game with betting.
The dealer (computer) deals two cards face up.
You have an option to bet or not, depending on whether or not you feel the next card will have a value between the first two.
##How to compile the program
This program consists of a single file, *acey-ducey.c*. Simply compile that to create an executable.
##How to run the program
The program does not use any command line arguments. When you run the program it will give you $100 and show you the first two cards and ask you to bet on whether the third card drawn will be between the first two. Enter a positive amount to bet or zero if you don't want to bet.

If you bet the program will draw the third card and let you know if you won or lost, adjusting your money reserves appropriately.

The game ends when you run out of money. You'll be asked if you want to play again. Enter "yes" if you want another game or "no" if you don't.

If you are interested, there's a [development diary](https://laurencescotford.com/games-programming-from-the-ground-up-with-c-challenge-project-1/) for this game.
