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
	Card(std::string name, int attack, int costMana);
	virtual void useOn(Card card) = 0;
	virtual void useOn(std::vector<Card> listOfCards) = 0;
	~Card();
};
