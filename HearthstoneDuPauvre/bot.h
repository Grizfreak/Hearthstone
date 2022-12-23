#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"


class Bot : public Player {
public:
	Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color);
	Bot();
	void autogame();
	~Bot();

};
	