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
	Spell(std::string name, int attack, int costMana, std::string imagePath, std::vector<Effect*> effects);
	/* Methods */
	void useOn(Card* card);
	void useOn(std::vector<Card*> listOfCards);
	/* Redefined Methods */
	friend std::ostream& operator<<(std::ostream& os, const Spell& spell);
	/* Getter */
	std::vector<Effect*> getEffects() const;
	/* Destructor */
	~Spell();
};


