// File deck.h
/*
Name: Deck 
Author: Alex Sylvanus
Description:
This is the deck header file. It includes the deck class declaration.
*/
#pragma once

// Includes
#include <cstdlib>
#include <time.h>
#include "card.h"

#ifndef DECK_H
#define DECK_H

// Create node structure
typedef struct node {
	card c;
	node* next;
}*card_node;

// Declare deck class
class deck{
public:
	deck();
	deck(const deck& D); // Copy Constructor
	deck & operator = (const deck& D); // Overload assignment operator
	~deck(); // Destructor
	void shuffle();
	card deal();
	void replace(card C);
	friend ostream& operator << (ostream& output, deck& D);
private:
	card_node head; 
	card_node curr;
};
#endif /* DECK_H */ 

