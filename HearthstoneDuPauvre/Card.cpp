#include <string>
#include <vector>
#include <iostream>

#include "Card.h"

/* Constructor */
Card::Card(std::string name, int attack, int costMana) {
	this->name = name; 
	this->attack = attack;
	this->costMana = costMana;
	this->cardRectangle = sf::RectangleShape(sf::Vector2f(120.f, 140.f));
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

sf::RectangleShape& Card::getCardRectangle()
{
	return this->cardRectangle;
}

/* Setters */
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
