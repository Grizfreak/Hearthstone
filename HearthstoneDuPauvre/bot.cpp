#include "Bot.h"


Bot::Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color) : Player(name, deck, pHRect, position, color) {
}


Bot::Bot(): Player() {
	
}
void Bot::autogame()
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->getCostMana() <= currentMana)
		{
			/*placeOnBoard(hand[i]);*/
		}
	}
	
}

Bot::~Bot() {
}






	

