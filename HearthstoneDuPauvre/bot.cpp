#include "bot.h"


bot::bot(std::string name, Deck* deck) : name(name), deck(deck) {
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
}

bot::bot() {
	health = 0;
	currentMana = 0;
	maxMana = 0;
	isAlive = false;
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}

Card* bot::draw() {
	Card* card = deck->getOneCard();
	hand.push_back(card);
	return card;
}

