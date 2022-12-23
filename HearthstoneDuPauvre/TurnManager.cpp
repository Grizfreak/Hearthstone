#include "TurnManager.h"

TurnManager::TurnManager(std::vector<Player*> players):listOfPlayers(players) {
	this->indexOfCurrentPlayer = 0;
	this->currentPlayer = this->listOfPlayers.at(indexOfCurrentPlayer);
}

void TurnManager::endturn()
{
	if (indexOfCurrentPlayer == listOfPlayers.size() - 1)
	{
		indexOfCurrentPlayer = 0;
	}
	else
	{
		indexOfCurrentPlayer++;
	}

	this->currentPlayer = this->listOfPlayers.at(indexOfCurrentPlayer);
}

TurnManager::~TurnManager()
{
	
}