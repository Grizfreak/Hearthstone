#include "TurnManager.h"

/* Constructor */
TurnManager::TurnManager(std::vector<Player*> players): listOfPlayers(players) {
	this->indexOfCurrentPlayer = 0;
	/* We initialize the current player turn with the first player in the list */
	this->currentPlayer = this->listOfPlayers.at(indexOfCurrentPlayer);
}

/* Method used to end the turn of a player */
void TurnManager::endturn()
{
	/* If we arrive at the end of the list, we reinitialize the index */
	if (indexOfCurrentPlayer == listOfPlayers.size() - 1)
	{
		indexOfCurrentPlayer = 0;
	}
	/* Else We increment the index*/
	else
	{
		indexOfCurrentPlayer++;
	}

	/* We update the current player and reset his mana */
	this->currentPlayer = this->listOfPlayers.at(indexOfCurrentPlayer);
	this->currentPlayer->incrementMaxmana();

	/* All Cards on board can now attack on the next turn */
	for (int i = 0; i < this->currentPlayer->getCardsOnBoard().size(); i++) {
		this->currentPlayer->getCardsOnBoard().at(i)->setCanAttack(true);
	}
}

/* Getter */
Player* TurnManager::getCurrentPlayer()
{
	return this->currentPlayer;
}

/* Destructor */
TurnManager::~TurnManager()
{
}