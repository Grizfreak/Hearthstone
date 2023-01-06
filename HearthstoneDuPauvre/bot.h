#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

/* Class bot used to symbolise the bot of the game */
class Bot : public Player {

/* Methods */
public:
	/* Constructor */
	Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color);
	/* Constructor */
	Bot();
	/* Bot is playing */
	void play(Player* ennemy);
	/* Destructor */
	~Bot();

};
	