#include <string>
#include <iostream>
#include <vector>

#include "Spell.h"

/* Constructor */
Spell::Spell(std::string name, int attack, int costMana, std::string imagePath, std::vector<Effect*> effects)
	: Card(name, attack, costMana, imagePath)
{
	this->effects = effects;
}

/* Method which is not used but we must implement it */
void Spell::useOn(Card* card)
{
}

/* Method which enable the spell to be used on a group of cards (allies or ennemies) */
void Spell::useOn(std::vector<Card*> listOfCards)
{
	for (Card* card : listOfCards)
	{
		this->useOn(card);
	}
}

/* Getter */
std::vector<Effect*> Spell::getEffects() const
{
	return this->effects;
}

/* Redefined operator << to print the informations about a spell */
std::ostream& operator<<(std::ostream& os, const Spell& spell)
{
	os << "Spell Description: \n"
		<< "Name: " << spell.getName() << "\n"
		<< "Attack: " << spell.getAttack() << "\n"
		<< "Cost Mana: " << spell.getCostMana() << "\n";
	return os;
}

/* Destructor */
Spell::~Spell() {
}