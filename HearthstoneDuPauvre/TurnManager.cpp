#include "TurnManager.h"

TurnManager::TurnManager(Player &player1)
{
	this->currentPlayer = &player1;
}

TurnManager::TurnManager()
{
	this->currentPlayer = NULL;
}

void TurnManager::setCurrentPlayer(Player& player)
{
	this->currentPlayer = &player;
}

void TurnManager::endturn()
{
}

TurnManager::~TurnManager()
{
	
}