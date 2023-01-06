#pragma once
#include <string>
#include <vector>

#include "Card.h"

/* Class Deck used to symbolise the deck of the game */
class Deck
{
/* Attributes */
private:
	std::vector<Card*> listOfCards;

/* Methods */
public:
	/* Constructor */
	Deck(std::vector<Card*> listOfCards);
	/* Method to randomise the cards */
	void shuffle();
	/* Method to get a card */
	Card* getOneCard();
	/* Return the lenght */
	int getLenght();
	/* Destructor */
	~Deck();
};