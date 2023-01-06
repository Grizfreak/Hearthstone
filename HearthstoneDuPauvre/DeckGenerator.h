#pragma once

#include "Deck.h"
#include "Minion.h"
#include "Spell.h"

/* Class DeckGenerator used to symbolise the generation of the deck */
class DeckGenerator {

/* Methods */
public:
	/* Constructor */
	DeckGenerator();
	/* Destructor */
	~DeckGenerator();
	/* Method to generate the deck 1 */
	Deck* generateDeck1();
	/* Method to generate the deck 2 */
	Deck* generateDeck2();
};