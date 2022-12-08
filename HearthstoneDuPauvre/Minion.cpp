#include <string>
#include <vector>

#include "Card.h"
#include "Minion.h"
#include "Status.h"
#include "TypeOfMonster.h"

Minion::Minion(std::string name, int attack, int costMana, int defense, Status status, TypeOfMonster type) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->type = type;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, Status status) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
}

Minion::Minion(std::string name, int attack, int costMana, int defense) : Card(name, attack, costMana) {
	this->defense = defense;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, TypeOfMonster type) : Card(name, attack, costMana) {
	this->defense = defense;
	this->type = type;
}

void useOn(Card card) {

}

void useOn(std::vector<Card> listOfCards) {

}

Minion::~Minion() {

}