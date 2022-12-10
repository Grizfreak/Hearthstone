#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "Player.h"

class Spell : public Card
{
private:
	std::vector<Effect*> effects;

public:
	/* Constructor */
	Spell(std::string name, int attack, int costMana, std::vector<Effect*> effects);
	/* Methods */
	void useOn(Card* card);
	void useOn(Player* player);
	void useOn(std::vector<Card*> listOfCards);
	/* Redefined Methods */
	friend std::ostream& operator<<(std::ostream& os, const Spell& spell);
	/* Destructor */
	~Spell();
};


