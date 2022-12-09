#pragma once
#include <string>
#include <vector>

class Card
{
private:
	int attack;
	int costMana;
	std::string name;

public:
	/* Constructor */
	Card(std::string name, int attack, int costMana);
	/* Methods */
	virtual void useOn(Card *card) = 0;
	virtual void useOn(std::vector<Card*> listOfCards) = 0;
	/* Getters */
	int getAttack() const;
	int getCostMana() const;
	std::string getName() const;
	/* Desctructor */
	~Card();
	/* Redefine Operator */
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};