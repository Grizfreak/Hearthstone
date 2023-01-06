#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Bonus.h"
#include "Target.h"

/* Class Effect used to symbolise the Effect of the game */
class Effect {

/* Attributes */
private:
	Bonus bonus;
	int value;
	Target target;

/* Methods */
public:

	/* Constructor */
	Effect(Bonus bonus, int value, Target target);
	/* Method to use a bonus interaction */
	std::string bonusToString(Bonus bonus) const;
	/* Method to use a target interaction */
	std::string targetToString(Target target) const;
	/* Getters*/
	Bonus getBonus() const;
	/* Return a value */
	int getValue() const;
	Target getTarget() const;
	/* Destructor */
	~Effect();
	/* Redefined methods */
	friend std::ostream& operator<<(std::ostream& os, const Effect& effect);
};