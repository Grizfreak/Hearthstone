#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Bonus.h"
#include "Target.h"

class Effect {
	
private:
	Bonus bonus;
	int value;
	Target target;

public:
	/* Constructor */
	Effect(Bonus bonus, int value, Target target);
	/* Methods */
	std::string bonusToString(Bonus bonus) const;
	std::string targetToString(Target target) const;
	/* Getters*/
	Bonus getBonus() const;
	int getValue() const;
	Target getTarget() const;
	/* Destructor */
	~Effect();
	/* Redefined methods */
	friend std::ostream& operator<<(std::ostream& os, const Effect& effect);
};