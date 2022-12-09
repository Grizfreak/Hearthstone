#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Bonus.h"
#include "Target.h"

class Card
{
private:
	int attack;
	int costMana;
	std::string name;
	sf::RectangleShape cardRectangle;

public:
	/* Constructor */
	Card(std::string name, int attack, int costMana);
	/* Methods */
	virtual void useOn(Card *card) = 0;
	virtual void useOn(std::vector<Card*> listOfCards) = 0;
	std::string bonusToString(std::vector<Bonus> bonus) const;
	std::string targetToString(std::vector<Target> target) const;
	/* Getters */
	int getAttack() const;
	int getCostMana() const;
	std::string getName() const;
	sf::RectangleShape& getCardRectangle();
	/* Setters */
	void setAttack(int attack);
	/* Destructor */
	~Card();
	/* Redefine Operator */
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};