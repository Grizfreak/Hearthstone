#include <string>
#include <vector>
#include <iostream>

#include "Minion.h"

/* Constructors */
Minion::Minion(std::string name, int attack, int costMana, int defense, Status status, TypeOfMonster type) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->type = type;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, Status status) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->type = TypeOfMonster::HUMAN;
}

Minion::Minion(std::string name, int attack, int costMana, int defense) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = Status::DEFAULT;
	this->type = TypeOfMonster::HUMAN;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, TypeOfMonster type) : Card(name, attack, costMana) {
	this->defense = defense;
	this->type = type;
	this->status = Status::DEFAULT;
}

/* Methods */
void Minion::useOn(Card* card)
{
	Minion *minionToAttack = dynamic_cast<Minion*>(card);
	std::cout << "Minion " << this->getName() << " attacks " << minionToAttack->getName() + "\n";
	std::cout << "Minion " << minionToAttack->getName() << " attacks " << this->getName() + "\n";
	minionToAttack->looseLife(this->getAttack());
	this->looseLife(minionToAttack->getAttack());
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
		case Status::DEFAULT:
			return "DEFAULT";
		case Status::PROVOCATION:
			return "PROVOCATION";
		case Status::DIVINE_SHIELD:
			return "DIVINE_SHIELD";
		case Status::RUSH:
			return "RUSH";
		default:
			return "DEFAULT";
	}
}

std::string Minion::typeOfMonsterToString(TypeOfMonster type) const
{
	switch (type)
	{
	case TypeOfMonster::HUMAN:
		return "HUMAN";
	case TypeOfMonster::MORT_VIVANT:
		return "MORT_VIVANT";
	case TypeOfMonster::MURLOC:
		return "MURLOC";
	default:
		return "HUMAN";
	}
}

void Minion::looseLife(int life)
{
	this->defense -= life;
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
		<< "\t - Type : " << minion.typeOfMonsterToString(minion.type) << "\n";
	return os;
}
