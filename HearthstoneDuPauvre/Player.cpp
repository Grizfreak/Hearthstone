#include "Player.h"
#include <iostream>

Player::Player(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color) :name(name), deck(deck) {
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

void Player::placeOnBoard(Card* card, Player enemy) {
	for (int i = 0; i < hand.size(); i++) {
		if (hand[i] == card) {
			if (currentMana >= card->getCostMana()) {
				currentMana -= card->getCostMana();

			if (typeid(*card) == typeid(Minion))
			{
				Minion* minion = dynamic_cast<Minion*>(card);
				if (minion->hasEffect()) {
					for (Effect* effect : minion->getEffects())
					{
						switch (effect->getBonus())
						{
						case Bonus::DAMAGE_BOOST:
							if (effect->getTarget() == Target::SINGLE) {
								/* TODO for a single card*/
							}
							else {
								for (Card* card : hand) {
									card->setAttack(card->getAttack() + effect->getValue());
								}
							}
							break;
						case Bonus::DAMAGE_MALUS:
							if (effect->getTarget() == Target::SINGLE) {
								/* TODO for a single card */
							}
							else {
								for (Card* card : enemy.hand) {
									card->setAttack(card->getAttack() - effect->getValue());
								}
							}
							break;
						case Bonus::DAMAGE_ON_PLAYER:
							enemy.setHealth(enemy.getHealth() - effect->getValue());
							break;
						case Bonus::DRAW_CARDS:
							for (int i = 0; i < effect->getValue(); i++) {
								draw();
							}
							break;
						case Bonus::MANA_BOOST:
							this->setCurrentMana(this->getCurrentMana() + effect->getValue());
							break;
						default:
							break;
						}
					}
				}
		
			}
			else if (typeid(*card) == typeid(Spell))
			{
				Spell* spell = dynamic_cast<Spell*>(card);
			}
			else {
				std::cout << "Error: Card is not a minion or a spell";
			}

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
std::vector<Card*> Player::getHand() {
	return hand;
}
std::vector<Card*> Player::getCardsOnBoard() {
	return cardsOnBoard;
}
sf::RectangleShape& Player::getPlayerHandRect() {
	return playerHandRect;
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