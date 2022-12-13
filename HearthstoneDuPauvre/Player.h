#pragma once
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Minion.h"
#include "Spell.h"
 
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
	Player(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color);
	Player();
	Card* draw();
	void placeOnBoard(Card* card, Player enemy);
	void incrementMaxmana();
	std::vector<Card*> getHand();
	std::vector<Card*> getCardsOnBoard();
	sf::RectangleShape& getPlayerHandRect();
	int getHealth();
	void setHealth(int health);
	int getCurrentMana();
	int getMaxMana();
	void setCurrentMana(int currentMana);
	~Player();
	
};