#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TurnManager.h"


class Board
{
private:
	Player player1;
	Player player2;
	TurnManager turnManager;
public:
	Board(Player player1, Player player2, TurnManager turnmanager);
	void dispawnCard(Card card);
	~Board();
};
