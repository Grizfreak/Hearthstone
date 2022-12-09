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
	sf::RectangleShape playerHandRect;
	
public:
	Player(std::string name, Deck* deck, sf::RectangleShape pHRect);
	Player();
	Card* draw();
	void placeOnBoard(Card* card);
	void incrementMaxmana();
	std::vector<Card*> getHand();
	std::vector<Card*> getCardsOnBoard();
	sf::RectangleShape& getPlayerHandRect();
	int getHealth();
	void setHealth(int health);
	int getCurrentMana();
	void setCurrentMana(int currentMana);
	~Player();
	
};