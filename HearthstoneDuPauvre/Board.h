#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "bot.h"
#include "TurnManager.h"


class Board
{
private:
	Player player1;
	Bot player2;
	TurnManager turnManager;
	sf::RectangleShape j1cardBoard;
	sf::RectangleShape j2cardBoard;
	sf::Sprite background;
public:
	Board(Player player1, Bot player2, TurnManager turnManager, sf::Texture* backgroundTexture);
	void dispawnCard(Card* card);
	Player& getPlayer1();
	Bot& getPlayer2();
	sf::RectangleShape& getJ1cardBoard();
	sf::RectangleShape& getJ2cardBoard();
	sf::Sprite& getBackground();
	TurnManager& getTurnManager();
	~Board();
};
