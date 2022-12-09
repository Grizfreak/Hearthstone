#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"


class bot : public Player{
public:
	bot(std::string name, Deck* deck);
	bot();
	void draw();
	void placeOnBoard(Card* card);
	void incrementMaxmana();
	void autogame();
	~bot();

};
	