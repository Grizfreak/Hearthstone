#include "DeckGenerator.h"

DeckGenerator::DeckGenerator()
{
}

DeckGenerator::~DeckGenerator()
{
}

Deck* DeckGenerator::generateDeck1()
{
	return new Deck(std::vector<Card*>() =
		{
			new Minion("Adepte Lige-Glaive", 6, 5, 4, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 3, Target::DEFAULT)}),
			/* Sofiane continue ici avec les cartes 2 à 30*/
		});
}

Deck* DeckGenerator::generateDeck2()
{
	return new Deck(std::vector<Card*>() =
		{
			new Spell("Arc cornedaigle", 0, 2, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::SINGLE), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT) }),
			/* Allan continue ici avec les cartes 32 à 60*/
		});
}
