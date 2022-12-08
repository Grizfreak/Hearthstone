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

/* Getters */
int Card::getAttack()
{
	return this->attack;
}

int Card::getCostMana()
{
	return this->costMana;
}

std::string Card::getName()
{
	return this->name;
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
