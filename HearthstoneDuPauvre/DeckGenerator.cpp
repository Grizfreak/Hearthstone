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
			new Minion("Adepte Lige-Glaive", 6, 5, "1.png", 4, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 3, Target::DEFAULT)}),
			new Spell("Cisaille d'ame",0,2,"3.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 3, Target::SINGLE)}),
			new Spell("Cisaille d'ame",0,2,"4.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 3, Target::SINGLE)}),
			new Spell("Crane de guldan",0,7,"5.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 3, Target::GROUP), new Effect(Bonus::DRAW_CARDS, 3, Target::DEFAULT)}),
			new Spell("Crane de guldan",0,7,"6.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 3, Target::GROUP), new Effect(Bonus::DRAW_CARDS, 3, Target::DEFAULT)}),
			new Spell("Danse des lames",0,2,"7.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 1, Target::GROUP)}),
			new Spell("Danse des lames",0,2,"8.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 1, Target::GROUP)}),
			new Spell("Entaille Jumelles",0,1,"9.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 2, Target::SINGLE)}),
			new Spell("Entaille Jumelles",0,1,"10.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 2, Target::SINGLE)}),
			new Minion("fabriquant de baguette", 3, 2, "11.png", 2),
			new Minion("fabriquant de baguette", 3, 2, "12.png", 2),
			new Spell("Frappe du Chaos",0,3,"13.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 2, Target::SINGLE), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT)}),
			new Spell("Frappe du Chaos",0,3,"14.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 2, Target::SINGLE), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT)}),
			new Spell("Geolier d'esprit",0,1,"15.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 1, Target::GROUP)}),
			new Spell("Geolier d'esprit",0,1,"16.png",std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 1, Target::GROUP)}),
			new Minion("Jongleur de crayon", 1, 1, "17.png", 1, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 1, Target::DEFAULT)}),
			new Minion("Jongleur de crayon", 1, 1, "18.png", 1, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 1, Target::DEFAULT)}),
			new Minion("Lame demon guerre arldarachi", 2, 3, "19.png", 2, RUSH_STATUS),
			new Minion("Lame demon guerre arldarachi", 2, 3, "20.png", 2, RUSH_STATUS),
			new Minion("lapidaire d'eclat de mana", 5, 5, "21.png", 5, std::vector<Effect*>() = { new Effect(Bonus::MANA_BOOST, 1, Target::DEFAULT)}),
			new Minion("lapidaire d'eclat de mana", 5, 5, "22.png", 5, std::vector<Effect*>() = { new Effect(Bonus::MANA_BOOST, 1, Target::DEFAULT)}),
			new Spell("Manavore",0,1,"23.png",std::vector<Effect*>() = { new Effect(Bonus::DRAW_CARDS, 2, Target::DEFAULT)}),
			new Spell("Manavore",0,1,"24.png",std::vector<Effect*>() = { new Effect(Bonus::DRAW_CARDS, 2, Target::DEFAULT)}),
			new Minion("Mystique briseclat", 4, 3, "25.png", 3,DIVINE_SHIELD_STATUS),
			new Minion("Mystique briseclat", 4, 3, "26.png", 3,DIVINE_SHIELD_STATUS),
			new Minion("Panthara devore mana", 2, 3, "27.png", 2),
			new Minion("Panthara devore mana", 2, 3, "28.png", 2),
			new Minion("Tranche moelle",4,4,"29.png",2, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 1, Target::GROUP), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT)}),
			new Minion("Tranche moelle",4,4,"30.png",2, std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 1, Target::GROUP), new Effect(Bonus::DRAW_CARDS, 1, Target::DEFAULT)}),
			

			
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
			new Spell("Infestation adorable", 0, 1, "38.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_BOOST, 1, Target::GROUP)}),
			new Minion("initie intrepide", 2, 2, "39.png", 2),
			new Minion("initie intrepide", 2, 2, "40.png", 2),
			new Minion("lacher de gorille", 4, 3, "41.png", 4),
			new Minion("lacher de gorille", 4, 3, "42.png", 4),
			new Minion("lectrice vorace", 1, 2, "43.png", 3, std::vector<Effect*>() = {new Effect(DAMAGE_BOOST, 1, Target::GROUP)}),
			new Minion("lectrice vorace", 1, 2, "44.png", 3, std::vector<Effect*>() = {new Effect(DAMAGE_BOOST, 1, Target::GROUP)}),
			new Spell("Ordre de tuer", 0, 3, "45.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 4, Target::SINGLE)}),
			new Spell("Ordre de tuer", 0, 3, "46.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_ON_PLAYER, 4, Target::SINGLE)}),
			new Spell("piege explosif", 0, 3, "47.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::GROUP)}),
			new Spell("piege explosif", 0, 3, "48.png", std::vector<Effect*>() = { new Effect(Bonus::DAMAGE_MALUS, 2, Target::GROUP)}),			
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
		});
}
