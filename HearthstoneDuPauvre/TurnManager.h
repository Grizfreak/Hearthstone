#pragma once
#include <string>
#include <vector>
#include "Player.h"



class TurnManager
{
private:
	Player *currentPlayer;
	int indexOfCurrentPlayer;
	std::vector<Player*> listOfPlayers;
public:
	TurnManager(std::vector<Player*> players);
	void endturn();
	~TurnManager();
};