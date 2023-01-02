#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "bot.h"
#include "TurnManager.h"

/* Class Board used to symbolise the board of the game */
class Board
{
	
/* Attributes */
private:
	Player* player1;
	Bot* player2;
	TurnManager* turnManager;
	sf::RectangleShape j1cardBoard;
	sf::RectangleShape j2cardBoard;
	sf::Sprite background;
	
/* Methods */
public:
	
	/* Constructor */
	
	/* Board default constructor
	* @param player1 : The first player of the game
	* @param player2 : The bot against we play
	* @param turnManager : The object used to handle whoose player is playing
	* @param backgroundTexture : The object on which we can write some text
	*/
	Board(Player* player1, Bot* player2, TurnManager* turnManager, sf::Texture* backgroundTexture);

	/* Getters */
	
	/* Method used to know the address of the first player
	* @returns The address of the first player
	*/
	Player& getPlayer1();

	/* Method used to know the address of the bot (the second player)
	* @returns The address of the second player
	*/
	Bot& getPlayer2();

	/* Method used to know the address of the rectangle used to symbolise the board of the first player
	* @returns The address of the rectangle board for the first player
	*/
	sf::RectangleShape& getJ1cardBoard();
	
	/* Method used to know the address of the rectangle used to symbolise the board of the second player
	* @returns The address of the rectangle board for the second player
	*/
	sf::RectangleShape& getJ2cardBoard();

	/* Method used to know the address of the background
	* @returns The address of the board's background
	*/
	sf::Sprite& getBackground();
	
	/* Method used to know the address of the turn manager 
	* @returns The address of the turn manager
	*/
	TurnManager& getTurnManager();

	/* Destructor */
	~Board();
};
