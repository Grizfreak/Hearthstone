#include "Bot.h"


Bot::Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color) : Player(name, deck, pHRect, position, color) {
	
}


Bot::Bot(): Player() {
	
}

void Bot::play(Player* ennemy)
{
	std::cout << "Bot is playing" << std::endl;

	std::cout << this->deck->getLenght();

	this->draw();

	/* Play the first card in the hand */
	this->placeOnBoard(this->getHand()[0], ennemy, nullptr);

	/* Attack the ennemy card to be sure to kill */
	if (ennemy->getCardsOnBoard().size() != 0) {
		for (Card* card : ennemy->getCardsOnBoard()) {
			/* Cast the card into a minion */
			Minion* ennemyMinion = dynamic_cast<Minion*>(card);
			if (ennemyMinion->getDefense() <= this->getCardsOnBoard()[0]->getAttack()) {
				this->getCardsOnBoard()[0]->useOn(ennemyMinion);
				
				Minion* minion = dynamic_cast<Minion*>(this->getCardsOnBoard()[0]);
				
				if (minion->getDefense() <= 0)
				{
					this->erase(minion);
				}
				if (ennemyMinion->getDefense() <= 0)
				{
					ennemy->erase(ennemyMinion);
				}
			}
		}
	}
}

Bot::~Bot() {
	
}