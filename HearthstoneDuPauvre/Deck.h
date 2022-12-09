#pragma once
#include <string>
#include <vector>

#include "Card.h"

class Deck
{
private:
	std::vector<Card*> listOfCards;

public:
	Deck(std::vector<Card*> listOfCards);
	void shuffle();
	Card* getOneCard();
	int getLenght();
	~Deck();
};