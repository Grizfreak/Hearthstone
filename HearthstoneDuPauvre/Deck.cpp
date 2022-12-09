#include <string>
#include <vector>
#include <algorithm>
#include <random>

#include "Deck.h"

Deck::Deck(std::vector<Card*> listOfCards) {
	this->listOfCards = listOfCards;
}

void Deck::shuffle() {
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->listOfCards), std::end(this->listOfCards), rng);
}

Card* Deck::getOneCard() {
	Card* card = this->listOfCards.back();
	this->listOfCards.pop_back();
	return card;
}

int Deck::getLenght()
{
	return (int)this->listOfCards.size();
}

Deck::~Deck() {

}