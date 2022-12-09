#include <string>
#include <vector>
#include <iostream>

#include "Card.h"

/* Constructor */
Card::Card(std::string name, int attack, int costMana) {
	this->name = name; 
	this->attack = attack;
	this->costMana = costMana;
}

std::string Card::bonusToString(std::vector<Bonus> bonus) const
{
	std::string bonusToReturn = "(";
	for (Bonus eachBonus : bonus) {
		switch (eachBonus) {
		case Bonus::DAMAGE_BOOST:
			bonusToReturn += "DAMAGE_BOOST, ";
			break;
		case Bonus::DAMAGE_MALUS:
			bonusToReturn += "DAMAGE_MALUS, ";
			break;
		case Bonus::DAMAGE_ON_PLAYER:
			bonusToReturn += "DAMAGE_ON_PLAYER, ";
			break;
		case Bonus::DRAW_CARDS:
			bonusToReturn += "DRAW_CARDS, ";
			break;
		case Bonus::MANA_BOOST:
			bonusToReturn += "MANA_BOOST, ";
			break;
		default:
			std::cout << "Error: Bonus not found";
		}
	}
	/* Remove the last ',' */
	bonusToReturn += ")";
	return bonusToReturn;
}

std::string Card::targetToString(std::vector<Target> target) const
{
	std::string targetToReturn = "(";
	for(Target eachTarget : target)
		switch (eachTarget)
		{
		case Target::DEFAULT:
			targetToReturn += "DEFAULT, ";
			break;
		case Target::GROUP:
			targetToReturn += "GROUP, ";
			break;
		case Target::SINGLE:
			targetToReturn += "SINGLE, ";
			break;
		default:
			std::cout << "Error: Target not found";
			break;
	}
	/* Remove the last ',' */
	targetToReturn += ")";
	return targetToReturn;
}

/* Getters */
int Card::getAttack() const
{
	return this->attack;
}

int Card::getCostMana() const
{
	return this->costMana;
}

std::string Card::getName() const
{
	return this->name;
}

void Card::setAttack(int attack)
{
	this->attack = attack;
}

/* Desctructor */
Card::~Card() {

}

/* Redefine Operator */
std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << "Card Description : \n" 
		<< "\t - Name : " << card.name << "\n"
		<< "\t - Attack : " << card.attack << "\n"
		<< "\t - Cost Mana : " << card.costMana << "\n";
	return os;
}
