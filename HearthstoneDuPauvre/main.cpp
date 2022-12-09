#include <string>
#include <vector>
#include <iostream>

#include "Deck.h"
#include "Minion.h"
#include "Spell.h"

int main() {
	/* Test for Deck */
	Spell* spell = new Spell("Spell1", 1, 1, TypeOfSpell::DAMAGE_BOOST);
	std::vector<Card*> deckForPlayer1{ new Minion("Minion1", 1, 1, 1), new Minion("Minion2", 2, 2, 2), new Minion("Minion3", 3, 3, 3), spell};
	Deck *deck = new Deck(deckForPlayer1);
	deck->shuffle();
	for (int i = 0; i < 4; i++) {
		std::cout << *(deck->getOneCard());
	}
	deck->shuffle();
	
	/* Test for a minion useOn another minion */
	Minion* minion1 = new Minion("Minion1", 1, 1, 1);
	Minion* minion2 = new Minion("Minion2", 2, 2, 2);
	minion1->useOn(minion2);
	std::cout << *minion2;
	std::cout << *minion1;
	std::cout << *spell;
	
	return 0;
}
