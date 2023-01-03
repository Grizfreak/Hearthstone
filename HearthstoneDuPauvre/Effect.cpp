#include "Effect.h"

/* Constructor */
Effect::Effect(Bonus bonus, int value, Target target)
{
	this->bonus = bonus;
	this->value = value;
	this->target = target;
}

/* Method useful to get the string value of the Bonus enum */
std::string Effect::bonusToString(Bonus bonus) const
{
	switch (bonus)
	{
	case Bonus::DAMAGE_BOOST:
		return "Damage Boost";
	case Bonus::DAMAGE_MALUS:
		return "Damage Malus";
	case Bonus::DAMAGE_ON_PLAYER:
		return "Damage on Player";
	case Bonus::DRAW_CARDS:
		return "Draw Cards";
	case Bonus::MANA_BOOST:
		return "Mana Boost";
	default:
		return "NULL";
	}
}

/* Method useful to get the string value of the Target enum */
std::string Effect::targetToString(Target target) const
{
	switch (target)
	{
	case Target::DEFAULT:
		return "Default";
	case Target::GROUP:
		return "Group";
	case Target::SINGLE:
		return "Single";
	default:
		return "NULL";
	}
}

/* Getters */
Bonus Effect::getBonus() const
{
	return this->bonus;
}

int Effect::getValue() const
{
	return this->value;
}

Target Effect::getTarget() const
{
	return this->target;
}

/* Redefined operator << to print the informations about the effect */
std::ostream& operator<<(std::ostream& os, const Effect& effect)
{
	os << "Effect: " << effect.bonusToString(effect.bonus) 
		<< ", " << effect.value 
		<< ", " << effect.targetToString(effect.target);
	return os;
}

/* Destructor */
Effect::~Effect()
{
}