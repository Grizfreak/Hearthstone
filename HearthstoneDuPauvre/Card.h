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
	void useOn(Card card);
	void useOn(std::vector<Card> listOfCards);
	~Card();
};
