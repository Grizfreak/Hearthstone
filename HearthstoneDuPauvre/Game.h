#pragma once
#include "Board.h"
#include "Player.h"
#include "Minion.h"
#include "bot.h"
#include "MusicManager.h"
#include <iostream>

class Game
{
private:
	Board* board;
	MusicManager musicManager;
public:
  Game(Board& board, MusicManager music);
	void displayMenu();
	void start();
	Player* checkWin();
	void displayGame();
	void drawGame(sf::RenderWindow& window, Card* selectedCard, Card* cardToDisplay, std::vector<sf::RectangleShape*> hitboxes, sf::Font font, sf::RectangleShape buttonEndTurn);
	void displayTexts(sf::RenderWindow& window);
	~Game();
};
	