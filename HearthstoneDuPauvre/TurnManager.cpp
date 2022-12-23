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
	this->currentPlayer->incrementMaxmana();

	/* All Cards on board can now attack on the next turn */
	for (int i = 0; i < this->currentPlayer->getCardsOnBoard().size(); i++) {
		this->currentPlayer->getCardsOnBoard().at(i)->setCanAttack(true);
	}
}


Player* TurnManager::getCurrentPlayer()
{
	return this->currentPlayer;
}

TurnManager::~TurnManager()
{
	
}