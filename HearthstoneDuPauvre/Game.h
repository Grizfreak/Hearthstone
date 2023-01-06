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
	Board* board; // The board of the game
	MusicManager musicManager; // The music manager of the game
public:
	Game(Board& board, MusicManager music); // Constructor
	void displayMenu(); // Display the menu of the game
	Player* checkWin(); // Check if there is a winner
	void displayGame(); // Display the game
	void drawGame(sf::RenderWindow& window, Card* selectedCard, Card* cardToDisplay, std::vector<sf::RectangleShape*> hitboxes, sf::Font font, sf::RectangleShape buttonEndTurn); // Draw all of interface
	void displayTexts(sf::RenderWindow& window); // Display the texts of the game
	Card* waitforMouseInput(sf::RenderWindow& window, std::vector<sf::RectangleShape*> hitboxes, Player* player1, Player* player2); // Wait for the mouse input
	void drawWin(sf::RenderWindow& window, Player* player, sf::Font font, Player* player1, Player* player2); // draw the winning screen
	~Game(); // Destructor
};
	