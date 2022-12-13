#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TurnManager.h"


class Board
{
private:
	Player player1;
	Player player2;
	TurnManager turnManager;
	sf::RectangleShape j1cardBoard;
	sf::RectangleShape j2cardBoard;
	sf::Sprite background;
public:
	Board(Player player1, Player player2, TurnManager turnManager, sf::Texture* backgroundTexture);
	void dispawnCard(Card* card);
	Player& getPlayer1();
	Player& getPlayer2();
	sf::RectangleShape& getJ1cardBoard();
	sf::RectangleShape& getJ2cardBoard();
	sf::Sprite& getBackground();
	TurnManager& getTurnManager();
	~Board();
};
