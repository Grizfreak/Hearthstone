#include "TurnManager.h"


TurnManager::TurnManager(Player &player1)
{
	currentPlayer = &player1;
}
TurnManager::~TurnManager()
{
}

void setCurrentPlayer(Player &player) {
	currentPlayer = &player;
}

void endTurn() {
	//fonction qui change le joueur courant
	
}