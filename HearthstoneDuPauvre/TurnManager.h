#pragma once
#include <string>
#include <vector>
#include "Player.h"



class TurnManager
{
private:
	Player *currentPlayer;
public:
	TurnManager(Player &player1);
	TurnManager();
	void setCurrentPlayer(Player &player);
	void endturn();
	~TurnManager();
};