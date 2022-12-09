#include "Board.h"

Board::Board(Player player1, Player player2, TurnManager turnManager)
{
    this->player1 = player1;
	this->player2 = player2;
	this->turnManager = turnManager;
}

Board::Board(){
	
}

Board::~Board(){
	
}

void Board::dispawnCard(Card* card) {
	//fonction qui delete une carte du board
	

}