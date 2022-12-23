#include "Bot.h"


Bot::Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color) : Player(name, deck, pHRect, position, color) {
	
}


Bot::Bot(): Player() {
	
}

void Bot::play(Player* ennemy)
{
	/* Draw cards while the bot doesn't have in his hand */
	if (this->getHand().size() == 0) {
		this->draw();
	}

	/* Play the first card in the hand */
	this->placeOnBoard(this->getHand()[0], ennemy);

	/* If he can, place another card */
	this->placeOnBoard(this->getHand()[0], ennemy);
	
	/* Attack the ennemy card to be sure to kill */
	for (Card* card : ennemy->getCardsOnBoard()) {
		/* Cast the card into a minion */
		Minion* minion = dynamic_cast<Minion*>(card);
		if (minion->getDefense() <= this->getCardsOnBoard()[0]->getAttack()) {
			this->getCardsOnBoard()[0]->useOn(minion);
		}
	}
	
}

Bot::~Bot() {
	
}