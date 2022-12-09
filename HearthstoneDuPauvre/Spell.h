#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "Player.h"

class Spell : public Card
{
private:
	std::vector<Bonus> bonus;
	std::vector<Target> targets;

public:
	/* Constructor */
	Spell(std::string name, int attack, int costMana, std::vector<Bonus> bonus, std::vector<Target> targets);
	Spell(std::string name, int attack, int costMana, std::vector<Bonus> bonus);
	/* Methods */
	void useOn(Card* card);
	void useOn(Player* player);
	void useOn(std::vector<Card*> listOfCards);
	/* Redefined Methods */
	friend std::ostream& operator<<(std::ostream& os, const Spell& spell);
	/* Destructor */
	~Spell();
};


