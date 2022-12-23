#pragma once
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Minion.h"
#include "Spell.h"
 
class Player
{ 
private:
	sf::Text manaText;
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
	sf::RectangleShape playerAvatar;
	sf::Text healthText;
	sf::Font font;
	std::vector<sf::Text> playerTexts;
	
	
public:
	Player(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color);
	Player();
	Card* draw();
	void placeOnBoard(Card* card, Player* enemy, Card* cardToTouch);
	void incrementMaxmana();
	void refreshTextDatas();
	std::vector<Card*> getHand();
	std::vector<Card*> getCardsOnBoard();
	sf::RectangleShape& getPlayerHandRect();
	std::vector<sf::Text>& getPlayerTexts();
	sf::RectangleShape& getPlayerAvatar();
	void erase(Minion* minion);
	Deck& getDeck() const;
	int getHealth();
	void setHealth(int health);
	int getCurrentMana();
	int getMaxMana();
	void setCurrentMana(int currentMana);
	~Player();
	
};