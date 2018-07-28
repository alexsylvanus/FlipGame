// File card.cpp
/*
Name: Card
Author: Alex Sylvanus
Description:
This file includes the definitions of all member/nonmember functions and operator overrides declared in the
card class header file.
*/

// Includes
#include "card.h"
#include <exception>

// Create card constructor
card::card() {
	setSuit(CLUB);
	setFace(TWO);
}

// Create Customizeable card constructor
card::card(SUIT s, FACE f) {
	try {
		setSuit(s);
		setFace(f);
	}
	catch (exception &ex) {
		cerr << ex.what() << endl;
	}
}

// Create copy card constructor
card::card(const card& C):suit(C.suit), value(C.value) {}

// Create override assignment operator
card & card::operator = (const card& C) {
	suit = C.suit;
	value = C.value;
	return *this;
}

// Create data access functions
SUIT card::getSuit() const {
	return suit;
}
FACE card::getFace() const {
	return value;
}

// Define convert to string functions used in output stream function
const char* getSuitString(SUIT s) {
	const char* str;
	// Pick return string constant based on enum
	switch (s) {
	case CLUB: str = club;
		break;
	case DIAMOND: str = diamond;
		break;
	case HEART: str = heart;
		break;
	case SPADE: str = spade;
		break;
	default:
		throw exception("Invalid string input");
		break;
	}
	return str;
}

const char* getFaceString(FACE f) {
	const char* str;
	switch (f) {
	case JACK: str = jack;
		break;
	case QUEEN: str = queen;
		break;
	case KING: str = king;
		break;
	case ACE: str = ace;
		break;
	default:
		throw exception("Invalid face input");
		break;
	}
	return str;
}

// Define override increment operators for looping through enum types
SUIT& operator ++ (SUIT& s) {
	switch (s) {
	case CLUB: return s = DIAMOND;
	case DIAMOND: return s = HEART;
	case HEART: return s = SPADE;
	default: return s = SPADE;
	}
}
FACE& operator ++ (FACE& f) {
	switch (f) {
	case TWO: return f = THREE;
	case THREE: return f = FOUR;
	case FOUR: return f = FIVE;
	case FIVE: return f = SIX;
	case SIX: return f = SEVEN;
	case SEVEN: return f = EIGHT;
	case EIGHT: return f = NINE;
	case NINE: return f = TEN;
	case TEN: return f = JACK;
	case JACK: return f = QUEEN;
	case QUEEN: return f = KING;
	case KING: return f = ACE;
	default: return f = ACE;
	}
}

// Define output stream function for printing card object data
ostream& operator << (ostream& ostr, const card &c) {
	try {
		if (c.value < JACK) {
			ostr << c.value << " of " << getSuitString(c.suit);
		}
		else {
			ostr << getFaceString(c.value) << " of " << getSuitString(c.suit);
		}
		return ostr;
	}
	catch (exception &ex) {
		cerr << ex.what() << endl;
	}
}

// Define initialize functions
void card::setSuit(SUIT s) {
	if (s > SPADE || s < CLUB) {
		throw exception("Invalid Suit");
	}
	else {
		suit = s;
	}
}
void card::setFace(FACE f) {
	if (f > ACE || f < TWO) {
		throw exception("Invalid Suit");
	}
	else {
		value = f;
	}
}