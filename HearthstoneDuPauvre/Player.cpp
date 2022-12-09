#include "Player.h"
#include <iostream>

Player::Player(std::string name, Deck* deck):name(name),deck(deck) {
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}

Player::Player() {
	health = 0;
	currentMana = 0;
	maxMana = 0;
	isAlive = false;
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}

void Player::draw() {
	/*if (deck.getDeck().size() > 0) {
		hand.push_back(deck.getDeck().back());
		deck.getDeck().pop_back();
	}
	else {
		std::cout << "Plus de carte dans le deck" << std::endl;
	}*/
}

void Player::placeOnBoard(Card* card) {
	/*if (card.getManaCost() <= currentMana) {
		cardsOnBoard.push_back(card);
		currentMana -= card.getManaCost();
	}
	else {
		std::cout << "pas assez de mana" << std::endl;
	}*/
}

void Player::incrementMaxmana() {
	if (maxMana < 10) {
		maxMana++;
		currentMana = maxMana;
	}
}

Player::~Player() {

}