#include "Player.h"
#include <iostream>

Player::Player(std::string name, Deck* deck, sf::RectangleShape pHRect):name(name),deck(deck) {
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
	this->playerHandRect = pHRect;
	this->playerHandRect.setFillColor(sf::Color::Transparent);
	this->playerHandRect.setOutlineColor(sf::Color::Red);
	this->playerHandRect.setOutlineThickness(5.f);
	this->playerHandRect.setPosition(350.f, 650.f);
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

std::vector<Card*> Player::getHand() {
	return hand;
}
std::vector<Card*> Player::getCardsOnBoard() {
	return cardsOnBoard;
}
sf::RectangleShape& Player::getPlayerHandRect() {
	return playerHandRect;
}

Player::~Player() {

}