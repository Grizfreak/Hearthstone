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
	if (this->deck->getLenght() > 0) {
		Card* card = deck->getOneCard();
		this->hand.push_back(card);
		return card;
	}    
}

void Player::placeOnBoard(Card* card, Player* enemy, Card* cardToTouch) {
	for (int i = 0; i < hand.size(); i++) {
		if (hand[i] == card) {
			if (currentMana >= card->getCostMana()) {
				currentMana -= card->getCostMana();

			if (typeid(*card) == typeid(Minion))
			{
				Minion* minion = dynamic_cast<Minion*>(card);
				Minion* cardToTouchMinion = dynamic_cast<Minion*>(cardToTouch);
				
				if (minion->hasEffect()) {
					for (Effect* effect : minion->getEffects())
					{
						switch (effect->getBonus())
						{
						case Bonus::DAMAGE_BOOST:
							if (effect->getTarget() == Target::SINGLE) {
								cardToTouch->setAttack(cardToTouch->getAttack() + effect->getValue());
								if (cardToTouch != nullptr) {
									std::cout << cardToTouch->getName() << std::endl;
								}
							}
							else {
								for (Card* card : hand) {
									card->setAttack(card->getAttack() + effect->getValue());
								}
							}
							break;
						case Bonus::DAMAGE_MALUS:
							if (effect->getTarget() == Target::SINGLE) {
								cardToTouchMinion->loseLife(effect->getValue());
								if (cardToTouch != nullptr) {
									std::cout << cardToTouch->getName() << std::endl;
								}
							}
							else {
								for (Card* card : enemy->getCardsOnBoard()) {
									Minion* minion = dynamic_cast<Minion*>(card);
									minion->loseLife(effect->getValue());
								}
							}
							break;
						case Bonus::DAMAGE_ON_PLAYER:
							enemy->setHealth(enemy->getHealth() - effect->getValue());
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
				Minion* cardToTouchMinion = dynamic_cast<Minion*>(cardToTouch);

					for (Effect* effect : spell->getEffects())
					{
						switch (effect->getBonus())
						{
						case Bonus::DAMAGE_BOOST:
							if (effect->getTarget() == Target::SINGLE) {
								cardToTouch->setAttack(cardToTouch->getAttack() + effect->getValue());
								if (cardToTouch != nullptr) {
									std::cout << cardToTouch->getName() << std::endl;
								}
							}
							else {
								for (Card* card : hand) {
									card->setAttack(card->getAttack() + effect->getValue());
								}
							}
							break;
						case Bonus::DAMAGE_MALUS:
							if (effect->getTarget() == Target::SINGLE) {
								cardToTouchMinion->loseLife(effect->getValue());
								if (cardToTouch != nullptr) {
									std::cout << cardToTouch->getName() << std::endl;
								}
							}
							else {
								for (Card* card : enemy->getCardsOnBoard()) {
									Minion* minion = dynamic_cast<Minion*>(card);
									minion->loseLife(effect->getValue());
								}
							}
							break;
						case Bonus::DAMAGE_ON_PLAYER:
							enemy->setHealth(enemy->getHealth() - effect->getValue());
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
			else {
				std::cout << "Error: Card is not a minion or a spell";
			}

			hand.erase(hand.begin() + i);
			if (typeid(*card) == typeid(Minion)) {
				cardsOnBoard.push_back(card);
			}
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

void Player::erase(Minion* minion)
{
	for (int i = 0; i < cardsOnBoard.size(); i++)
	{
		Minion* minionOnBoard = dynamic_cast<Minion*>(cardsOnBoard[i]);
		if (minionOnBoard == minion)
		{
			cardsOnBoard.erase(cardsOnBoard.begin() + i);
		}
	}
}

 Deck& Player::getDeck() const {
	return *this->deck;
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