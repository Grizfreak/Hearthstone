#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"


class bot {
private:
	std::string name;
	std::vector<Card*> hand;
	Deck* deck;
	bool isAlive;
	std::vector<Card*> cardsOnBoard;
	int maxMana;
	int currentMana;
	int health;

public:
	bot(std::string name, Deck* deck);
	bot();
	Card* draw();
	void placeOnBoard(Card* card);
	void incrementMaxmana();
	void autogame();
	~bot();

};
	