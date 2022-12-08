#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "TypeOfSpell.h"

class Spell
{
private:
	TypeOfSpell typeOfSpell;

public:
	Spell(std::string name, int attack, int costMana, TypeOfSpell typeOfSpell);
	void useOn(Card card);
	void useOn(std::vector<Card> listOfCards);
	~Spell();
};


