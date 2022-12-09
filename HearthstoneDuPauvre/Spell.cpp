#include <string>
#include <iostream>
#include <vector>

#include "Spell.h"

Spell::Spell(std::string name, int attack, int costMana, TypeOfSpell typeOfSpell) : Card(name, attack, costMana) {
	this->typeOfSpell = typeOfSpell;
}

void Spell::useOn(Card* card)
{
}

void Spell::useOn(std::vector<Card*> listOfCards)
{
}

std::string Spell::typeOfSpellToString(TypeOfSpell typeOfSpell) const
{
	switch (typeOfSpell)
	{
		case TypeOfSpell::ATTACK:
			return "ATTACK";
		case TypeOfSpell::DAMAGE_BOOST:
			return "DAMAGE_BOOST";
		case TypeOfSpell::HEAL_BOOST:
			return "HEAL_BOOST";
		default:
			return "UNKNOWN";
	}
}

Spell::~Spell() {

}

std::ostream& operator<<(std::ostream& os, const Spell& spell)
{
	os << "Spell Description: \n"
		<< "Name: " << spell.getName() << "\n"
		<< "Attack: " << spell.getAttack() << "\n"
		<< "Cost Mana: " << spell.getCostMana() << "\n"
		<< "Type of Spell: " << spell.typeOfSpellToString(spell.typeOfSpell) << "\n";
	return os;
}