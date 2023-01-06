#pragma once
#include <string>
#include <vector>
#include "Player.h"



class TurnManager
{
private:
	Player* currentPlayer; // The current player
	int indexOfCurrentPlayer; // The index of the current player 
	std::vector<Player*> listOfPlayers; // The list of players
public:
	TurnManager(std::vector<Player*> players); // Constructor
	void endturn(); // End the turn of the current player  
	/* Getter */
	Player* getCurrentPlayer(); // Return the current player
	~TurnManager(); // Destructor
};