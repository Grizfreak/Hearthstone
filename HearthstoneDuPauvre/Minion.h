#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "Status.h"
#include "Effect.h"

class Minion : public Card
{
private:
	Status status;
	int defense;
	std::vector<Effect*> effects;

public:
	/* Constructors */
	Minion(std::string name, int attack, int costMana, int defense, Status status);
	Minion(std::string name, int attack, int costMana, int defense);
	Minion(std::string name, int attack, int costMana, int defense, Status status, std::vector<Effect*> effects);
	Minion(std::string name, int attack, int costMana, int defense, std::vector<Effect*> effects);
	/* Methods */
	void useOn(Card* card);
	void useOn(std::vector<Card*> listOfCards);
	std::string statusToString(Status status) const;
	/* Setters */
	void loseLife(int life);
	void gainLife(int life);
	/* Redefined operators */
	friend std::ostream& operator<<(std::ostream& os, const Minion& minion);
	~Minion();
};
