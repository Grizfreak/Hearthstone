#include <string>
#include <vector>

#include "Card.h"

Card::Card(std::string name, int attack, int costMana) {
	this->name = name; 
	this->attack = attack;
	this->costMana = costMana;
}

void useOn(Card card) {

}

void useOn(std::vector<Card> listOfCards) {

}

Card::~Card() {

}