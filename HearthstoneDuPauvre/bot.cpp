#include "bot.h"


bot::bot(std::string name, Deck* deck) {
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}


bot::bot() {
	health = 0;
	currentMana = 0;
	maxMana = 0;
	isAlive = false;
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}

void bot::draw() {
	Card* card = deck->getOneCard();
	hand.push_back(card);
}

void bot::placeOnBoard(Card* card) {

	if (card->getCostMana() <= currentMana) {
		cardsOnBoard.push_back(card);
		currentMana -= card->getCostMana();
		for (int i = 0; i < hand.size(); i++)
			if (hand[i] == card) {
				hand.erase(hand.begin() + i);
			}
	}
}

void bot::incrementMaxmana() {
	if (maxMana < 10) {
		maxMana++;
		currentMana = maxMana;
	}
}

void bot::autogame()
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->getCostMana() <= currentMana)
		{
			placeOnBoard(hand[i]);
		}
	}
	
}




bot::~bot() {
}






	

