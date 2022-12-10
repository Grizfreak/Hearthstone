#pragma once

#include "Deck.h"
#include "Minion.h"
#include "Spell.h"

class DeckGenerator {
public:
	DeckGenerator();
	~DeckGenerator();
	Deck* generateDeck1();
	Deck* generateDeck2();
};