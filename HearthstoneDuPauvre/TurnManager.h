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
	TurnManager();
	void endturn();
	~TurnManager();
};