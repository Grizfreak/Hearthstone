#include <string>
#include <vector>
#include <iostream>

#include "Minion.h"

/* Constructors */
Minion::Minion(std::string name, int attack, int costMana, int defense, Status status) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->bonus = std::vector<Bonus>();
	this->targets = std::vector<Target>();
}

Minion::Minion(std::string name, int attack, int costMana, int defense) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = Status::DEFAULT_STATUS;
	this->bonus = std::vector<Bonus>();
	this->targets = std::vector<Target>();
}

Minion::Minion(std::string name, int attack, int costMana, int defense, Status status, std::vector<Bonus> bonus, std::vector<Target> targets)
	: Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->bonus = bonus;
	this->targets = targets;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, std::vector<Bonus> bonus, std::vector<Target> targets)
	: Card(name, attack, costMana) {
	this->defense = defense;
	this->status = Status::DEFAULT_STATUS;
	this->bonus = bonus;
	this->targets = targets;
}

/* Methods */
void Minion::useOn(Card* card)
{
	Minion *minionToAttack = dynamic_cast<Minion*>(card);
	std::cout << "Minion " << this->getName() << " attacks " << minionToAttack->getName() + "\n";
	std::cout << "Minion " << minionToAttack->getName() << " attacks " << this->getName() + "\n";
	minionToAttack->loseLife(this->getAttack());
	this->loseLife(minionToAttack->getAttack());
}

void Minion::useOn(std::vector<Card*> listOfCards)
{
	std::cout << "Un minion ne peut pas attaquer plusieurs cibles en meme temps";
	return;
}

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

void Minion::loseLife(int life)
{
	this->defense -= life;
}

void Minion::gainLife(int life)
{
	this->defense += life;
}

/* Destructors */
Minion::~Minion() {

}

/* Redefined operators */
std::ostream& operator<<(std::ostream& os, const Minion& minion)
{
	os << "Minion Description : \n"
		<< "\t - Name : " << minion.getName() << "\n"
		<< "\t - Attack : " << minion.getAttack() << "\n"
		<< "\t - Cost Mana : " << minion.getCostMana() << "\n"
		<< "\t - Defense : " << minion.defense << "\n"
		<< "\t - Status : " <<  minion.statusToString(minion.status) << "\n"
		<< "\t - Bonus : " << minion.bonusToString(minion.bonus) << "\n"
		<< "\t - Targets : " << minion.targetToString(minion.targets) << "\n";
	return os;
}
