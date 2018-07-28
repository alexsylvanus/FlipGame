// File card.h
/*
Name: Card
Author: Alex Sylvanus
Description:
This is the card class header file. It includes the string constants for the card face and suit variables,
the declaration of the face and suit enumerated types, the declaration of the override operators for the face
and suit enumerated types, the getString functions for printing the suit and face, and the card class declaration.
*/

#pragma once

// Includes
#include <iostream>

using namespace std;

#ifndef CARD_H
#define CARD_H

/* NOTE
Because it was unclear what kind of variable types the suit and face variables declared in the card class should be, I defined them as 
new enumerated types so that when creating the card objects, the card constructor can only take correct inputs, thus reducing the need
for catching incorrect implementations of the functions.
Because of this, I needed to define a way of looping through the new variable type, since they are not technically integer types, so
I overrode the ++ operator for the SUIT and FACE types. I also implemented functions to turn the enumerated types into string values,
which are then called in the print card functionality.
*/

// Define Suit types, to prevent impromper inputs to card member functions
typedef enum {
	CLUB = 1,
	DIAMOND = 2,
	HEART = 3,
	SPADE = 4
}SUIT;

// Define Number/Face types, to prevent impromper inputs to card member functions
typedef enum {
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
}FACE;

// Define suit constant strings
const char club[] = "clubs";
const char diamond[] = "diamonds";
const char heart[] = "hearts";
const char spade[] = "spades";

// Define Number/Face strings
/*
const string two = "two";
const string three = "three";
const string four = "four";
const string five = "five";
const string six = "six";
const string seven = "seven";
const string eight = "eight";
const string nine = "nine";
const string ten = "ten";*/
const char jack[] = "Jack";
const char queen[] = "Queen";
const char king[] = "King";
const char ace[] = "Ace";

// Over write increment operater for FACE variable types.
// Allows the ability to use ++[FACE] to move through card type
SUIT& operator ++ (SUIT& s);

// Over write increment operater for FACE variable types.
// Allows the ability to use ++[FACE] to move through card type
FACE& operator ++ (FACE& f);

// Define functions for turning enum types into strings
const char* getSuitString(SUIT s);
const char* getFaceString(FACE f);

// Declare card class
class card {
public:
	card();
	card(SUIT s, FACE f);
	card(const card& C); // Copy constructor
	card& operator = (const card& C); // Overload assignment operator
	SUIT getSuit() const;
	FACE getFace() const;
	friend ostream& operator << (ostream& ostr, const card &c);
private:
	void setSuit(SUIT s);
	void setFace(FACE f);
	SUIT suit;
	FACE value;
};
#endif /* CARD_H */
