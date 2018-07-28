// File deck.cpp
/*
Name: Deck
Author:	Alex Sylvanus
Description:
This file includes the definitions of the member functions for the deck class. 
*/

#include "deck.h"
/*
Deck class constructor

@use: Initializes a deck object, and creates a linked list of card objects. 

*/
deck::deck() {
	// Initialize head pointer
	head = new node;
	curr = head;

	// Declare FACE and SUIT variables to be looped through
	FACE F;
	SUIT S;
	for (F = TWO; F < ACE; ++F) { // Loop through faces, starting at TWO
		for (S = CLUB; S < SPADE; ++S) { // Loop through suits for each new face, starting with CLUBS
			curr->c = card(S, F); // set the current nodes card value equal to a new card, initialized by the surrent suit and face
			curr->next = new node;
			curr = curr->next;
		}
		// Finish inner Loop for S = SPADE
		curr->c = card(S, F);
		curr->next = new node;
		curr = curr->next;
	}
	// Finish outer loop for F = ACE;
	for (S = CLUB; S < SPADE; ++S) { // Loop through suits for each new face, starting with CLUBS
		curr->c = card(S, F); // set the current nodes card value equal to a new card, initialized by the surrent suit and face
		curr->next = new node;
		curr = curr->next;
	}
	curr->c = card(S, F);
	curr->next = NULL;

	// Verify that Deck was created
	if (head != NULL) {
		cout << "___Deck Created___\n";
	}
	else {
		cout << "Failed to create\n";
	}
}

/*
Deck class copy constructor

@use: Copies a previously created deck to a new deck object

*/
deck::deck(const deck& D) {
	// Create new pointer for head
	head = new node;

	// Set the current position to the front
	curr = head;

	// Create temporary pointer that starts at the copied deck's front
	card_node temp = D.head;

	// Loop through the copied deck, assigning card values of copied deck to new deck
	while (temp != NULL) {
		curr->c = temp->c;
		temp = temp->next;
		// Create new nodes until the end of the list, where the next pointer will be set to NULL 
		if (temp != NULL) {
			curr->next = new node;
			curr = curr->next;
		}
		else {
			curr->next = NULL;
		}
	}
	// Delete the temporary card_node pointer
	delete temp;

	// Set the current pointer to the front of the list
	curr = head;
}

/*
Overload assignment operator function

@use: Ability to assign two decks equal to eachother

*/
deck & deck::operator = (const deck& D) {
	// Assign the pointer values equal to eachother
	*head = *D.head;
	*curr = *D.curr;
	return *this;
}

/*
Destructor

@use: Frees the memory allocated by the deck object

*/
deck::~deck() {
	while (curr != NULL) {
		curr = head->next;
		delete head;
		head = curr;
	}
	cout << "Deck deleted! " << endl;
}

/*
Override output stream operater function

@use: able to print class data in cout streams 

*/
ostream& operator << (ostream& output, deck& D) {
	D.curr = D.head;
	int i = 0;
	output << "Current Stack of Cards:\n";
	while (D.curr != NULL) {
		i++;
		output << "Card " << i << ":   " << D.curr->c << endl;
		D.curr = D.curr->next;
	}
	return output;
}

/*
Shuffle function

@use: shuffle the deck

*/
void deck::shuffle() {
	// Initialize random number generator
	srand(time(NULL));
	// Create temporary card variables
	card_node temp;
	card card_temp;
	curr = head;
	int ran_index = 0;

	for (int j = 0; j < 52; j++) {
		// Generate random integer between 1 and number of card left in deck
		ran_index = rand() % (52 - j);

		// Set temporary pointer equal to pointer		
		temp = curr;

		// Set temporary card equal to current card
		card_temp = curr->c;

		// Move forward in deck by random number, 
		for (int n = 0; n < ran_index; n++) {
			temp = temp->next;
		}

		// Swap values of cards 
		curr->c = temp->c;
		temp->c = card_temp;

		// Move on to next card
		curr = curr->next;
	}
}

// Return the card at the top of the deck
card deck::deal() {
	// Set return card to value of head card
	card ret(head->c);

	// Set the current pointer to the next card
	curr = head->next;

	// Free the space of the top card
	delete head;

	// Set new front to the current node pointer
	head = curr;

	// Return the original card value
	return ret;
}

// Add a card to the bottom of the deck
void deck::replace(card C) {
	curr = head;
	if (curr == NULL) {
		head = new node;
		head->c = C;
	}
	else {
		while (curr != NULL) {
			curr = curr->next;
		}
		curr = new node;
		curr->c = C;
		curr->next = NULL;
	}
}