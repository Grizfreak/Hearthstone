#include <string>
#include <vector>

#include "Deck.h"

Deck::Deck(std::vector<Card*> listOfCards) {
	this->listOfCards = listOfCards;
}

void Deck::shuffle() {

}

Card* Deck::getOneCard() {
	return NULL;
}

Deck::~Deck() {

}