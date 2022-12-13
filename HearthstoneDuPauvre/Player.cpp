#include "Player.h"
#include <iostream>

Player::Player(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color):name(name), deck(deck) {
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
	this->playerHandRect = pHRect;
	this->playerHandRect.setFillColor(sf::Color::Transparent);
	this->playerHandRect.setOutlineColor(color);
	this->playerHandRect.setOutlineThickness(5.f);
	this->playerHandRect.setPosition(position);
	
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);

	if (!this->font.loadFromFile("./assets/arial.ttf")) {
		std::cout << "Error loading font for card " + this->name << std::endl;
	}
	this->healthText = sf::Text(std::to_string(this->health), this->font, 40);
	this->healthText.setFillColor(sf::Color::White);
	this->manaText = sf::Text(std::to_string(this->currentMana) + "/" + std::to_string(this->maxMana), this->font, 40);
	this->manaText.setFillColor(sf::Color::Blue);
	this->playerTexts = std::vector<sf::Text>();
	this->playerTexts.push_back(this->healthText);
	this->playerTexts.push_back(this->manaText);
	this->playerAvatar = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
	this->playerAvatar.setFillColor(color);
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
			if (currentMana >= card->getCostMana()) {
				currentMana -= card->getCostMana();
				hand.erase(hand.begin() + i);
				cardsOnBoard.push_back(card);
			}
		}
	}
}

void Player::incrementMaxmana() {
	if (maxMana < 10) {
		maxMana++;
		currentMana = maxMana;
	}
}

void Player::refreshTextDatas() {
	this->healthText.setString(std::to_string(this->health));
	this->manaText.setString(std::to_string(this->currentMana) + "/" + std::to_string(this->maxMana));
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

std::vector<sf::Text>& Player::getPlayerTexts() {
	return this->playerTexts;
}

sf::RectangleShape& Player::getPlayerAvatar() {
	return this->playerAvatar;
}

int Player::getHealth()
{
	return this->health;
}

void Player::setHealth(int health)
{
	this->health = health;
}

int Player::getCurrentMana()
{
	return this->currentMana;
}

int Player::getMaxMana() {
	return this->maxMana;
}

void Player::setCurrentMana(int currentMana)
{
	this->currentMana = currentMana;
}

Player::~Player() {

}