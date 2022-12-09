#pragma once
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
 
class Player
{ 
protected:
	int health;
	std::string name;
	std::vector<Card*> hand;
	Deck* deck;
	bool isAlive;
	std::vector<Card*> cardsOnBoard;
	int maxMana;
	int currentMana;
	
public:
	Player(std::string name, Deck* deck);
	Player();
	void draw();
	Card* placeOnBoard(Card* card);
	void incrementMaxmana();
	~Player();
	
};