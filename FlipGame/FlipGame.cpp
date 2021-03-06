// FlipGame.cpp : Defines the entry point for the console application.
/*
Name: FlipGame
Author: Alex Sylvanus
Description:
This is the main file for the FlipGame applications. It defines the main function for the game operation.
*/

// Includes
#include "deck.h"
void playFlip();
const char rules[] = "Gameplay:\n  10 points for an ace\n  \
5 points for a king, queen or jack\n  \
0 points for an 8, 9 or 10\n  \
loses half their points for a 7\n  \
loses all their points for a 2, 3, 4, 5 or 6\n  \
1 point extra, in addition to the above, for a heart.";

int main()
{
	// I am writing this code in Visual Studio, so I add this user input so that the console window doesn't
	// immediately shut down after the code is finished running.
	int in;

	// Play game
	playFlip();
	cout << "Enter any integer to quit program: ";
	cin >> in;

    return 0;
}

// playFlip function definition
void playFlip() {
	deck Deck;
	int i = 0;
	// Shuffle 3 times
	for (i = 0; i < 3; i++) {
		Deck.shuffle();
		cout << "Deck shuffle " << i+1 << endl;
	}
	cout << endl << "Deck shuffled!" << endl;

	// Reset increment variable
	i = 0;

	// Create temporary card values
	card current_card;
	FACE f = current_card.getFace();
	SUIT s = current_card.getSuit();

	// Create user input variable
	char usr_input = '1';

	// Create points variable
	int points = 0;

	// Dipsplay the gameplay rules
	cout << endl << rules << endl;
	cout << "Welcome to flip!" << endl << "To draw a card enter any character. To end the game, enter 0: ";

	// Start game on users command
	cin >> usr_input;

	// Loop while the user continues to draw cards, or until the deck runs out of cards
	while (usr_input != '0' && i < 52) {
		// Get the top card of the deck
		current_card = Deck.deal();
		f = current_card.getFace();
		s = current_card.getSuit();
		cout << "You drew the " << current_card << "." << endl;
		
		// Compute face condition
		if (f == ACE) {
			points = points + 10;
		}
		else if (f < ACE && f > TEN) {
			points = points + 5;
		}
		else if (f == SEVEN) {
			points = points / 2;
		}
		else if (f < SEVEN) {
			points = 0;
		}
		// Compute suit condition
		if (s == HEART) {
			points = points + 1;
		}

		// Display points
		cout << "You have " << points << " points." << endl;

		// Prompt user to continue playing, or end the game.
		cout << "To draw again enter any character. To end the game, enter 0: ";
		cin >> usr_input;
		// Count to 52 cards, then quit
		i++;
	}
	// Display score
	cout << endl << "Game over.\nYour total score was: " << points << " points" << endl;
}