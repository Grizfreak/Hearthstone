#include <string>
#include <vector>
#include <algorithm>
#include <random>

#include "Deck.h"

/* Constructor */
Deck::Deck(std::vector<Card*> listOfCards) {
	this->listOfCards = listOfCards;
}

/* Method used to shuffle the deck*/
void Deck::shuffle() {
	/* Initialization of the object which enables us to shuffle*/
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->listOfCards), std::end(this->listOfCards), rng);
}

/* Method used to get the card on the top of the deck */
Card* Deck::getOneCard() {
	Card* card = nullptr;
	/* Check if the deck contains enough cards */
	if (this->getLenght() > 0) {
		card = this->listOfCards.back();
	}
	this->listOfCards.pop_back();
	return card;
}

/* Method used to know the length of the deck */
int Deck::getLenght()
{
	return (int)this->listOfCards.size();
}

/* Destructor */
Deck::~Deck() {

}