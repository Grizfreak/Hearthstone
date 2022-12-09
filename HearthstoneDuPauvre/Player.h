#pragma once
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
 
class Player
{ 
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
	Player(std::string name, Deck* deck);
	Player();
	void draw();
	void placeOnBoard(Card* card);
	void incrementMaxmana();
	int getHealth();
	void setHealth(int health);
	int getCurrentMana();
	void setCurrentMana(int currentMana);
	~Player();
	
};