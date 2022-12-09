#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "TypeOfSpell.h"

class Spell : public Card
{
private:
	TypeOfSpell typeOfSpell;

public:
	/* Constructor */
	Spell(std::string name, int attack, int costMana, TypeOfSpell typeOfSpell);
	/* Methods */
	void useOn(Card* card);
	void useOn(std::vector<Card*> listOfCards);
	std::string typeOfSpellToString(TypeOfSpell typeOfSpell) const;
	/* Redefined Methods */
	friend std::ostream& operator<<(std::ostream& os, const Spell& spell);
	/* Destructor */
	~Spell();
};


