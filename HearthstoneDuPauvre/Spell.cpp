#include <string>
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

Spell::~Spell() {

}