#include <string>
#include <iostream>
#include <vector>

#include "Spell.h"
#include "Minion.h"


Spell::Spell(std::string name, int attack, int costMana, std::vector<Bonus> bonus, std::vector<Target> targets)
	: Card(name, attack, costMana)
{
	this->bonus = bonus;
	this->targets = targets;
}

Spell::Spell(std::string name, int attack, int costMana, std::vector<Bonus> bonus)
	: Card(name, attack, costMana)
{
	this->bonus = bonus;
	this->targets = std::vector<Target>();
}

void Spell::useOn(Card* card)
{
	for (Bonus bonus : this->bonus)
	{
		switch (bonus) {
		case Bonus::DAMAGE_BOOST:
			card->setAttack(card->getAttack() + this->getAttack());
			break;
		case Bonus::DAMAGE_MALUS:
			card->setAttack(card->getAttack() - this->getAttack());
			break;
		default:
			std::cout << "This spell can't be used on a card\n";
			break;
		}
	}
}

void Spell::useOn(Player* player)
{
	for (Bonus bonus : this->bonus)
	{
		switch (bonus)
		{
		case Bonus::DAMAGE_ON_PLAYER:
			player->setHealth(player->getHealth() - this->getAttack());
			break;
		case Bonus::DRAW_CARDS:
			std::cout << "Not implemented yet\n";
			break;
		case Bonus::MANA_BOOST:
			player->setCurrentMana(player->getCurrentMana() + this->getAttack());
			break;
		default:
			std::cout << "This spell can't be used on a player\n";
			break;
		}
	}
}

void Spell::useOn(std::vector<Card*> listOfCards)
{
	for (Card* card : listOfCards)
	{
		this->useOn(card);
	}
}

Spell::~Spell() {

}

std::ostream& operator<<(std::ostream& os, const Spell& spell)
{
	os << "Spell Description: \n"
		<< "Name: " << spell.getName() << "\n"
		<< "Attack: " << spell.getAttack() << "\n"
		<< "Cost Mana: " << spell.getCostMana() << "\n"
		<< "Bonus: " << spell.bonusToString(spell.bonus) << "\n"
		<< "Targets: " << spell.targetToString(spell.targets) << "\n";
	return os;
}