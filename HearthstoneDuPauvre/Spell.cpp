#include <string>
#include <vector>

#include "Card.h"
#include "Spell.h"
#include "TypeOfSpell.h"

Spell::Spell(std::string name, int attack, int costMana, TypeOfSpell typeOfSpell) : Card(name, attack, costMana) {
	this->typeOfSpell = typeOfSpell;
}

void useOn(Card card) {

}

void useOn(std::vector<Card> listOfCards) {

}

Spell::~Spell() {

}