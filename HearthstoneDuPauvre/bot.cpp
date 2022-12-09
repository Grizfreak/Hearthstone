#include "Bot.h"


bot::bot(std::string name, Deck* deck) : Player(name, deck) {
}


bot::bot(): Player() {
	
}
void bot::autogame()
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->getCostMana() <= currentMana)
		{
			placeOnBoard(hand[i]);
		}
	}
	
}

bot::~bot() {
}






	

