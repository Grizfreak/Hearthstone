#include "Bot.h"


Bot::Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color) : Player(name, deck, pHRect, position, color) {
	
}


Bot::Bot(): Player() {
	
}

void Bot::play(Player* ennemy)
{
	std::cout << "Bot is playing" << std::endl;

	/* First, bot draw a card */
	this->draw();

	/* Play the first card in the hand */
	if (this->getHand().size() > 0) {
		Card* selectedCard = this->getHand()[0];
		if (this->getCardsOnBoard().size() < 7 && typeid(*selectedCard) == typeid(Minion)) {
				Minion* minion = dynamic_cast<Minion*>(selectedCard);
				if (minion->hasEffect()) {
					int cpt = 0;
					for (int i = 0; i < minion->getEffects().size(); i++) {
						if (minion->getEffects()[i]->getTarget() == SINGLE) {
							cpt++;
							break;
						}
					}
					if (cpt == 0) {
						this->placeOnBoard(this->getHand()[0], ennemy, nullptr);
					}
					else {
						if (ennemy->getCardsOnBoard().size() > 0) {
							Card* cardTotouchWithEffect = ennemy->getCardsOnBoard()[0];
							this->placeOnBoard(selectedCard, ennemy, cardTotouchWithEffect);
						}
					}
				}
				else {
					this->placeOnBoard(this->getHand()[0], ennemy, nullptr);
				}
			
		}
		else if (typeid(*selectedCard) == typeid(Spell)) {
			Spell* spell = dynamic_cast<Spell*>(selectedCard);
			int cpt = 0;
			for (int i = 0; i < spell->getEffects().size(); i++) {
				if (spell->getEffects()[i]->getTarget() == SINGLE) {
					cpt++;
					break;
				}
			}
			if (cpt == 0) {
				this->placeOnBoard(this->getHand()[0], ennemy, nullptr);
				std::cout << "Spell used on a group of card" << std::endl;
				for (int i = 0; i < ennemy->getCardsOnBoard().size(); i++) {
					Minion* minion = dynamic_cast<Minion*>(ennemy->getCardsOnBoard()[i]);
					std::cout << "Minion: " << minion->getDefense() << std::endl;
					if (minion->getDefense() <= 0) {
						(*ennemy).erase(minion);
					}
				}
			}
			else {
				if (ennemy->getCardsOnBoard().size() > 0) {
					Card* cardTotouchWithEffect = ennemy->getCardsOnBoard()[0];
					this->placeOnBoard(selectedCard, ennemy, cardTotouchWithEffect);
					Minion* minionToTouchWithEffect = dynamic_cast<Minion*>(cardTotouchWithEffect);
					if (minionToTouchWithEffect->getDefense() <= 0) {
						(*ennemy).erase(minionToTouchWithEffect);
					}
				}
			}
		}
	}

	/* Attack the first ennemy card */
	if (ennemy->getCardsOnBoard().size() != 0) {
		/* Cast the card into a minion */
		Minion* ennemyMinion = dynamic_cast<Minion*>(ennemy->getCardsOnBoard()[0]);
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

	/* If nothing is on the board, attack the player with all the cards on board */
	else {
		for (int k = 0; k < this->getCardsOnBoard().size(); k++) {
			if (this->getCardsOnBoard()[k]->getCanAttack()) {
				this->attackPlayerWithCard(this->getCardsOnBoard()[k], ennemy);
			}
		}
	}
}

Bot::~Bot() {
	
}