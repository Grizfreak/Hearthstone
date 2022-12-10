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
			new Minion("Adepte Lige-Glaive", 6, 5, "1.png", 4, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 3, Target::DEFAULT)}),
			/* Sofiane continue ici avec les cartes 2 à 30*/
		});
}

Deck* DeckGenerator::generateDeck2()
{
	return new Deck(std::vector<Card*>() =
		{
			new Spell("Arc cornedaigle", 0, 2, "31.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::SINGLE), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT) }),
			new Spell("Arc cornedaigle", 0, 2, "32.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::SINGLE), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT) }),
			new Minion("compagnon animal", 3, 3, "33.png", 4),
			new Minion("compagnon animal", 3, 3, "34.png", 4),
			new Minion("Guide", 1, 2, "35.png", 4),
			new Minion("Guide", 1, 2, "36.png", 4),
			
			new Spell("Infestation adorable", 0, 1, "37.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 1, Target::GROUP)}),
			//pas sûr la carte doit boost NOTRE group de monstre la j'ai peur qu'elle boot tout le board pas que les notres
			new Spell("Infestation adorable", 0, 1, "38.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 1, Target::GROUP)}),
			//same card
			
			new Minion("initié intrépide", 2, 2, "39.png", 2),
			new Minion("initié intrépide", 2, 2, "40.png", 2),
			new Minion("lacher de gorille", 4, 3, "41.png", 4),
			new Minion("lacher de gorille", 4, 3, "42.png", 4),
			
			new Minion("lectrice vorace", 1, 2, "43.png", 3, std::vector<Effect*>() = {new Effect(DAMAGE_BOOST, 1, Target::GROUP)}),
			//Sofiane ce chien à pas defini ce que ça donne je vais pas lui donner 1 de pain zeubi "donne +1" je suppose de degat et same que "infestation adorable"
			new Minion("lectrice vorace", 1, 2, "44.png", 3, std::vector<Effect*>() = {new Effect(DAMAGE_BOOST, 1, Target::GROUP)}),
			//same card

			new Spell("Ordre de tuer", 0, 3, "45.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 4, Target::SINGLE)}),
			new Spell("Ordre de tuer", 0, 3, "46.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 4, Target::SINGLE)}),
			
			new Spell("piege explosif", 0, 3, "47.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::GROUP)}),
			//same que infestation adorable
			new Spell("piege explosif", 0, 3, "48.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::GROUP)}),
			//same card
			
			new Spell("piege givrant", 0, 2, "49.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::SINGLE)}),
			new Spell("piege givrant", 0, 2, "50.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::SINGLE)}),
			new Minion("pillard ingenieux", 2, 2, "51.png", 2, std::vector<Effect*>() = { new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT)}),
			new Minion("pillard ingenieux", 2, 2, "52.png", 2, std::vector<Effect*>() = { new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT) }),
			new Minion("plaque de pression", 1, 1, "53.png", 3),
			new Minion("plaque de pression", 1, 1, "54.png", 3),
			new Minion("tireur de precision nain", 1, 1, "55.png", 4),
			new Minion("tireur de precision nain", 1, 1, "56.png", 4),
			new Minion("traqueur phasique", 2, 2, "57.png", 5),
			new Minion("traqueur phasique", 2, 2, "58.png", 5),
			new Minion("Wolpertinger", 0, 0, "59.png", 2),
			new Minion("Wolpertinger", 0, 0, "60.png", 2),
			/* Allan continue ici avec les cartes 32 à 60*/
		});
}
