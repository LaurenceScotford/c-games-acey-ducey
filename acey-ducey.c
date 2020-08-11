//
//  acey-ducey.c
//  Acey Ducey
//
//  Created by Laurence Scotford on 01/05/2014.
//  Copyright (c) 2014 Laurence Scotford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

// Function declarations
void runGame();
int pickCard();
void getCardName(int card, char cardName[]);
void strToLowerCase(char string[]);

int main() {
    // Display instructions
    printf("Acey Ducey card game\nBased on a programme from Creative Computing, Morristown, New Jersey\n\n\nAcey Ducey is played in the following manner.\nThe dealer (computer) deals two cards face up.\nYou have an option to bet or not, depending\non whether or not you feel the next card will have\na value between the first two.\n\nIf you do not want to bet, input a 0\n");

    char rawInput[80];    // This will hold the raw input entered by the user
    char inputString[80]; // This will hold the processed input string

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    do {
        // Play a game
        runGame();

        // Ask the player if they want to play again
        printf("\nTry Again (yes or no)? ");
        fgets(rawInput, sizeof(rawInput), stdin);
        sscanf(rawInput, " %s", inputString);
        strToLowerCase(inputString);
    } while (!strncmp(inputString, "yes", 3));

    printf("\nOK. Hope you had fun!\n\n");

    return 0;
}

void runGame() {
    char rawInput[80];          // This will hold the raw input entered by the user
    int bet = 0;                // This will hold the amount of the player's bet

    int money = 100;   // Amount of money remaining to the player

    // Keep playing while the player has money remaining
    while (money > 0) {
        // Show player how much money is remaining
        printf("\n\nYou now have %i dollars\n\n", money);

        // Pick first card
        int cardA = pickCard();
        int cardB = cardA;

        // Continue picking second card until it is not the same as first card
        while (cardB == cardA) {
            cardB = pickCard();
        }

        // If cardB is lower than cardA, swap them
        if(cardB < cardA)
        {
            int tmp = cardA;
            cardA = cardB;
            cardB = tmp;
        }

        // Get the card names
        char cardAName[6];
        char cardBName[6];
        getCardName(cardA, cardAName);
        getCardName(cardB, cardBName);

        // Show the cards to the player
        printf("Here are your next two cards:\n%s\n%s\n\n", cardAName, cardBName);

        // Get the player's bet
        bool validBet = false;

        // Continue to ask for player's bet until player enters a valid amount
        while (!validBet) {
            printf("What is your bet? ");

            fgets(rawInput, sizeof(rawInput) / sizeof(rawInput[0]), stdin);

            // Attempt to convert bet to a number
            int varsFilled = sscanf(rawInput, " %i", &bet);

            // Only validate bet if it's a positive number equal to or less than player's money, otherwise display an error message
            if (varsFilled != 1 || bet < 0) {
                printf("\nPlease enter 0 for no bet or a whole number greater than zero to bet that amount.\n\n");
            } else if(bet > money) {
                printf("\nSorry my friend but you bet too much.\nYou only have %i dollars to bet.\n\n", money);
            } else {
                validBet = true;
            }
        }

        // Only pick third card if player has chosen to bet
        if (bet == 0) {
            printf("\nChicken!\n");
        } else {
            // Pick third card
            int cardC = pickCard();

            // Get name of third card
            char cardCName[6];
            getCardName(cardC, cardCName);

            // Display third card to player
            printf("\n%s\n", cardCName);

            // Check if player has won or lost
            if( cardA < cardC && cardC < cardB ) {
                printf("You win!!!\n");
                money += bet;
            } else {
                printf("Sorry, you lose.\n");
                money -= bet;
            }
        }
    }

    printf("\nSorry friend, but you blew your wad.\n");
}

// This function returns a card picked at random
int pickCard() {
    return rand() % 13 + 2;
}

// This function returns the correct card name for the card passed as the first argument,
// the second argument is a character array where the card name will be stored (which must have space for at least six characters)
void getCardName(int card, char cardName[]) {
      switch(card) {
        case 11:
            strcpy(cardName, "Jack");
            break;
        case 12:
            strcpy(cardName, "Queen");
            break;
        case 13:
            strcpy(cardName, "King");
            break;
        case 14:
            strcpy(cardName, "Ace");
            break;
        default:
            sprintf(cardName, "%i", card);
            break;
    }
}

// This function converts the string to lower case letters
void strToLowerCase(char string[]) {
    for(int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}
