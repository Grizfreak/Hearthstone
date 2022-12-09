#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "Status.h"
#include "TypeOfMonster.h"

class Minion : public Card
{
private:
	Status status;
	TypeOfMonster type;
	int defense;

public:
	/* Constructors */
	Minion(std::string name, int attack, int costMana, int defense, Status status, TypeOfMonster type);
	Minion(std::string name, int attack, int costMana, int defense, Status status);
	Minion(std::string name, int attack, int costMana, int defense);
	Minion(std::string name, int attack, int costMana, int defense, TypeOfMonster type);
	/* Methods */
	void useOn(Card* card);
	void useOn(std::vector<Card*> listOfCards);
	std::string statusToString(Status status) const;
	std::string typeOfMonsterToString(TypeOfMonster type) const;
	/* Setters */
	void loseLife(int life);
	/* Redefined operators */
	friend std::ostream& operator<<(std::ostream& os, const Minion& minion);
	~Minion();
};