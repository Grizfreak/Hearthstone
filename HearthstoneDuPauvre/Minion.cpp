#include <string>
#include <vector>
#include <iostream>

#include "Minion.h"

/* Constructors */

/* Detailled constructor */
Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, Status status) : Card(name, attack, costMana, imagePath) {
	
	/* Useful informations */
	this->defense = defense;
	this->status = status;
	this->effects = std::vector<Effect*>();

	/* Texts */
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);

	/* Status */
	if (this->status == Status::RUSH_STATUS) {
		this->setCanAttack(true);
	}
	if (this->status == Status::DIVINE_SHIELD_STATUS) {
		this->setDivineShield(true);
	}
}

/* Detailled constructor */
Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense) : Card(name, attack, costMana, imagePath) {
	/* Useful informations */
	this->defense = defense;
	this->status = Status::DEFAULT_STATUS;
	this->effects = std::vector<Effect*>();

	/* Texts */
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);
}

/* Detailled constructor */
Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, Status status, std::vector<Effect*> effects)
	: Card(name, attack, costMana, imagePath) {
	/* Useful informations */
	this->defense = defense;
	this->status = status;
	this->effects = effects;

	/* Texts */
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);

	/* Status*/
	if (this->status == Status::RUSH_STATUS) {
		this->setCanAttack(true);
	}
	if (this->status == Status::DIVINE_SHIELD_STATUS) {
		this->setDivineShield(true);
	}
}

/* Detailled constructor */
Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, std::vector<Effect*> effects)
	: Card(name, attack, costMana, imagePath) {
	/* Useful informations */
	this->defense = defense;
	this->status = Status::DEFAULT_STATUS;
	this->effects = effects;

	/* Texts */
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);
}

/* Method used to use a minion on another minion */
void Minion::useOn(Card* card)
{
	/* If the card can attack */
	if (this->getCanAttack() == true) {
		/* Cast the card into a minion so it can access it's following attributes */
		Minion* minionToAttack = dynamic_cast<Minion*>(card);

		/* Each minion lose life by attacking each other */
		if (minionToAttack->getDivineShield() == false) {
			minionToAttack->loseLife(this->getAttack());
		}
		/* MinionToAttack owns a divine shield */
		else {
			minionToAttack->setDivineShield(false);
		}
		
		/* Each minion lose life by attacking each other */
		if (this->getDivineShield() == false) {
			this->loseLife(minionToAttack->getAttack());
		}
		/* MinionToAttack owns a divine shield */
		else {
			this->setDivineShield(false);
		}	

		/* The card can't attack several times */
		this->setCanAttack(false);
	}
	else {
		std::cout << "The card can't attack on this turn";
	}
}

/* Method used to use a minion on a list of cards - Not possible */
void Minion::useOn(std::vector<Card*> listOfCards)
{
	std::cout << "A minion cannot attack several targets at the same time";
	return;
}

/* Method used to get the string value of the status */
std::string Minion::statusToString(Status status) const
{
	switch (status)
	{
		case Status::DEFAULT_STATUS:
			return "DEFAULT";
		case Status::PROVOCATION_STATUS:
			return "PROVOCATION";
		case Status::DIVINE_SHIELD_STATUS:
			return "DIVINE_SHIELD";
		case Status::RUSH_STATUS:
			return "RUSH";
		default:
			return "DEFAULT";
	}
}

/* Method used to refresh texts of the player (mana and health)*/
void Minion::refreshTextDatas() {
	this->defenseText.setString(std::to_string(this->defense));
	Card::refreshTextDatas();
}

/* Method sued to refresh texts positions */
std::vector<sf::Vector2f> Minion::refreshTextPositions() {
	std::vector<sf::Vector2f> positions = Card::refreshTextPositions();
	positions.push_back(sf::Vector2f(this->cardRectangle.getPosition().x + 120, this->cardRectangle.getPosition().y + 130));
	return positions;
}

/* Method which remove life from the player */
void Minion::loseLife(int life)
{
	this->defense -= life;
}

/* Method which gain life of a player */
void Minion::gainLife(int life)
{
	this->defense += life;
}

/* Getters */
int Minion::getDefense()
{
	return this->defense;
}

bool Minion::hasEffect()
{
	bool hasEffect = this->effects.size() > 0;
	return hasEffect;
}

std::vector<Effect*> Minion::getEffects()
{
	return this->effects;
}

/* Redefined operators << to print information about a minion */
std::ostream& operator<<(std::ostream& os, const Minion& minion)
{
	os << "Minion Description : \n"
		<< "\t - Name : " << minion.getName() << "\n"
		<< "\t - Attack : " << minion.getAttack() << "\n"
		<< "\t - Cost Mana : " << minion.getCostMana() << "\n"
		<< "\t - Defense : " << minion.defense << "\n"
		<< "\t - Status : " << minion.statusToString(minion.status) << "\n";
	return os;
}

/* Destructors */
Minion::~Minion() {
}
