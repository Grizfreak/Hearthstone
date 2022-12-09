#include "Bot.h"


Bot::Bot(std::string name, Deck* deck, sf::RectangleShape pHRect) : Player(name, deck, pHRect) {
}


Bot::Bot(): Player() {
	
}
void Bot::autogame()
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->getCostMana() <= currentMana)
		{
			placeOnBoard(hand[i]);
		}
	}
	
}

Bot::~Bot() {
}






	

