#include <string>
#include <iostream>
#include <vector>

#include "Spell.h"


Spell::Spell(std::string name, int attack, int costMana, std::string imagePath, std::vector<Effect*> effects)
	: Card(name, attack, costMana, imagePath)
{
	this->effects = effects;
}

void Spell::useOn(Card* card)
{
}

void Spell::useOn(std::vector<Card*> listOfCards)
{
	for (Card* card : listOfCards)
	{
		this->useOn(card);
	}
}

Spell::~Spell() {

}

std::ostream& operator<<(std::ostream& os, const Spell& spell)
{
	os << "Spell Description: \n"
		<< "Name: " << spell.getName() << "\n"
		<< "Attack: " << spell.getAttack() << "\n"
		<< "Cost Mana: " << spell.getCostMana() << "\n";
	return os;
}