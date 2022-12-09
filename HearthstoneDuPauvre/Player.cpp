#include "Player.h"
#include <iostream>

Player::Player(std::string name, Deck* deck):name(name),deck(deck) {
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
}

Player::Player() {
	health = 0;
	currentMana = 0;
	maxMana = 0;
	isAlive = false;
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}

Card* Player::draw() {
	Card* card = deck->getOneCard();
	hand.push_back(card);
	return card;
          
}

void Player::placeOnBoard(Card* card) {
	for (int i = 0; i < hand.size(); i++) {
		if (hand[i] == card) {
			hand.erase(hand.begin() + i);
			cardsOnBoard.push_back(card);
		}
	}
}

void Player::incrementMaxmana() {
	if (maxMana < 10) {
		maxMana++;
		currentMana = maxMana;
	}
}

Player::~Player() {

}