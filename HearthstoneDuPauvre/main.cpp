#include <string>
#include <vector>
#include <iostream>

#include "Deck.h"
#include "Minion.h"

int main() {
	/* Test for Deck */
	std::vector<Card*> deckForPlayer1{ new Minion("Minion1", 1, 1, 1), new Minion("Minion2", 2, 2, 2), new Minion("Minion3", 3, 3, 3) };
	Deck *deck = new Deck(deckForPlayer1);
	deck->shuffle();
	for (int i = 0; i < 3; i++) {
		std::cout << *(deck->getOneCard());
	}
	
	return 0;
}
