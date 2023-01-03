#include "Player.h"
#include <iostream>

/* Constructors */

/* Detailled Constructor */
Player::Player(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color):name(name), deck(deck) {
	/* Useful informations */
	health = 35;
	currentMana = 2;
	maxMana = 2;
	isAlive = true;
	
	/* Rectangles */
	this->playerHandRect = pHRect;
	this->playerHandRect.setFillColor(sf::Color::Transparent);
	this->playerHandRect.setOutlineColor(color);
	this->playerHandRect.setOutlineThickness(5.f);
	this->playerHandRect.setPosition(position);
	
	/* Cards of the player */
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);

	/* Font */
	if (!this->font.loadFromFile("./assets/arial.ttf")) {
		std::cout << "Error loading font for card " + this->name << std::endl;
	}

	/* Texts */
	this->healthText = sf::Text(std::to_string(this->health), this->font, 40);
	this->healthText.setFillColor(sf::Color::White);
	this->manaText = sf::Text(std::to_string(this->currentMana) + "/" + std::to_string(this->maxMana), this->font, 40);
	this->manaText.setFillColor(sf::Color::Blue);

	/* List of texts (health and mana texts) */
	this->playerTexts = std::vector<sf::Text>();
	this->playerTexts.push_back(this->healthText);
	this->playerTexts.push_back(this->manaText);

	/* Avatar of the player */
	this->playerAvatar = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
	this->playerAvatar.setFillColor(color);
}

/* Default constructor */
Player::Player() {
	/* Useful informations */
	health = 0;
	currentMana = 0;
	maxMana = 0;
	isAlive = false;
	
	/* Cards */
	std::vector<Card*> listOfCards;
	deck = new Deck(listOfCards);
}

/* Method which enables the player to draw a card from his deck */
Card* Player::draw() {
	
	/* We check if the deck contains cards and if the number of "onBoard" cards is less than 10 */
	if (this->deck->getLenght() > 0 && this->hand.size() < 10) {

		/* Get the card and push it to the hand of the player */
		Card* card = deck->getOneCard();
		this->hand.push_back(card);
		
		return card;
	}
	else
	{
		return nullptr;
	}
}

/* Method which enable a player to attack the other player with a card */
void Player::attackPlayerWithCard(Card* card, Player* enemy) {
	
	/* We check if the card can attack */
	if (card->getCanAttack()) {
		enemy->setHealth(enemy->getHealth() - card->getAttack());
		card->setCanAttack(false);
	}
}

/* Method which allows the player to place a card on board and eventually attack one card if effects */
void Player::placeOnBoard(Card* card, Player* enemy, Card* cardToTouch) {
	
	for (int i = 0; i < hand.size(); i++) {
		if (hand[i] == card) {
			
			/* If the player has enough mana */
			if (currentMana >= card->getCostMana()) {
				currentMana -= card->getCostMana();

			/* If this is a minion */
			if (typeid(*card) == typeid(Minion))
			{
				/* Cast the two cards useful for the fight */
				Minion* minion = dynamic_cast<Minion*>(card);
				Minion* cardToTouchMinion = dynamic_cast<Minion*>(cardToTouch);
				
				/* If there is any effects */
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
			
			/* If the card is a spell */
			else if (typeid(*card) == typeid(Spell))
			{
				/* Casting cards useful for the fight */
				Spell* spell = dynamic_cast<Spell*>(card);
				Minion* cardToTouchMinion = dynamic_cast<Minion*>(cardToTouch);

					for (Effect* effect : spell->getEffects())
					{
						switch (effect->getBonus())
						{
						case Bonus::DAMAGE_BOOST:
							if (effect->getTarget() == Target::SINGLE) {
								if (cardToTouch != nullptr) {
									cardToTouch->setAttack(cardToTouch->getAttack() + effect->getValue());
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

			/* After that, we remove that card from the hand of the player */
			hand.erase(hand.begin() + i);
			
			/* If this is a minion, we place it on the board */
			if (typeid(*card) == typeid(Minion)) {
				cardsOnBoard.push_back(card);
			}
			}
		}
	}
}

/* Method which increment the maxMana of the player */
void Player::incrementMaxmana() {

	/* The maxMana is 10 */
	if (maxMana < 10) {
		maxMana++;
		currentMana = maxMana;
	}
	currentMana = maxMana;
}

/* Method which refresh texts (health and mana one) */
void Player::refreshTextDatas() {
	this->healthText.setString(std::to_string(this->health));
	this->manaText.setString(std::to_string(this->currentMana) + "/" + std::to_string(this->maxMana));
}

/* Getters */
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

Deck& Player::getDeck() const {
	return *this->deck;
}

int Player::getHealth()
{
	return this->health;
}

int Player::getCurrentMana()
{
	return this->currentMana;
}

int Player::getMaxMana() {
	return this->maxMana;
}

/* Method which erase a card from the player's hand (because of death) */
void Player::erase(Minion* minion)
{
	for (int i = 0; i < cardsOnBoard.size(); i++)
	{
		/* We cast the card into a minion because a spell can't die */
		Minion* minionOnBoard = dynamic_cast<Minion*>(cardsOnBoard[i]);

		/* If the minion is the desired one */
		if (minionOnBoard == minion)
		{
			cardsOnBoard.erase(cardsOnBoard.begin() + i);
		}
	}
}

/* Setters */
void Player::setHealth(int health)
{
	this->health = health;
}

void Player::setCurrentMana(int currentMana)
{
	this->currentMana = currentMana;
}

/* Destructor */
Player::~Player() {
}