#include "Bot.h"

/* Constructors */

/* Detailled constructor */
Bot::Bot(std::string name, Deck* deck, sf::RectangleShape pHRect, sf::Vector2f position, sf::Color color) : Player(name, deck, pHRect, position, color) {
	
}

/* Default constructor */
Bot::Bot(): Player() {
	
}

/* Method which enable the bot to automaticcaly play a card */
void Bot::play(Player* ennemy)
{

	/* First, bot draw a card */
	this->draw();

	/* Play the first card in the hand */
	if (this->getHand().size() > 0) {
		Card* selectedCard = this->getHand()[0];
		
		/* If the card is a minion */
		if (this->getCardsOnBoard().size() < 7 && typeid(*selectedCard) == typeid(Minion)) {
				Minion* minion = dynamic_cast<Minion*>(selectedCard);
				
				/* If the minion has somme effects, deal with them */
				if (minion->hasEffect()) {
					int cpt = 0;
					/* Use the cpt variable to know who is the target of the effect */
					for (int i = 0; i < minion->getEffects().size(); i++) {
						if (minion->getEffects()[i]->getTarget() == SINGLE) {
							cpt++;
							break;
						}
					}
					/* If the target is a group of cards, that's explains the nullptr */
					if (cpt == 0) {
						this->placeOnBoard(this->getHand()[0], ennemy, nullptr);
					}
					/* If the target is single */
					else {
						if (ennemy->getCardsOnBoard().size() > 0) {
							Card* cardTotouchWithEffect = ennemy->getCardsOnBoard()[0];
							this->placeOnBoard(selectedCard, ennemy, cardTotouchWithEffect);
						}
					}
				}
				/* If the minion doesn't have any effects, then place it on the board */
				else {
					this->placeOnBoard(this->getHand()[0], ennemy, nullptr);
				}
			
		}
		/* If the card is a spell */
		else if (typeid(*selectedCard) == typeid(Spell)) {
			Spell* spell = dynamic_cast<Spell*>(selectedCard);
			
			int cpt = 0;
			int cptPlayer = 0;
			
			/* If the spell has somme effects, deal with them */
			for (int i = 0; i < spell->getEffects().size(); i++) {
				if (spell->getEffects()[i]->getTarget() == SINGLE) {
					cpt++;
					/* If one of the effetc is damage on player, initialize the corresponding variable */
					if (spell->getEffects()[i]->getBonus() == Bonus::DAMAGE_ON_PLAYER) {
						cptPlayer = spell->getEffects()[i]->getValue();
					}
					break;
				}
			}
			/* If the target is a group of cards, that's explains the nullptr */
			if (cpt == 0 && this->cardsOnBoard.size() > 0) {
				this->placeOnBoard(this->getHand()[0], ennemy, nullptr);
				
				/* The loop is to know if one of the player's card id dead */
				for (int i = 0; i < ennemy->getCardsOnBoard().size(); i++) {
					Minion* minion = dynamic_cast<Minion*>(ennemy->getCardsOnBoard()[i]);
					
					/* If the minion is dead, then we remove it from the board */
					if (minion->getDefense() <= 0) {
						(*ennemy).erase(minion);
					}
				}
			}
			/* If one of the effect is damage on player */
			else if (cptPlayer != 0) {
				std::cout << "Spell attack on player";
				this->placeOnBoard(spell, ennemy, nullptr);
			}
			else {
				if (ennemy->getCardsOnBoard().size() > 0) {
					/* We get the card to touch */
					Card* cardTotouchWithEffect = ennemy->getCardsOnBoard()[0];
					this->placeOnBoard(selectedCard, ennemy, cardTotouchWithEffect);

					/* We cast the card into a minion to access to it's defense */
					Minion* minionToTouchWithEffect = dynamic_cast<Minion*>(cardTotouchWithEffect);
					
					/* If the minion is dead, then we remove it from the board */
					if (minionToTouchWithEffect->getDefense() <= 0) {
						(*ennemy).erase(minionToTouchWithEffect);
					}
				}
			}
		}
	}

	/* Attack the first ennemy card if there are any cards on board  */
	if (ennemy->getCardsOnBoard().size() != 0 && this->getCardsOnBoard().size() != 0) {
		
		/* Cast the card into a minion */
		Minion* ennemyMinion = dynamic_cast<Minion*>(ennemy->getCardsOnBoard()[0]);
		this->getCardsOnBoard()[0]->useOn(ennemyMinion);
		
		Minion* minion = dynamic_cast<Minion*>(this->getCardsOnBoard()[0]);
		
		/* If one of the minion is dead, then we remove it from the board */
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
			
			/* We check if the card can attack (A card can't attack on the same turn it was placed)*/
			if (this->getCardsOnBoard()[k]->getCanAttack()) {
				this->attackPlayerWithCard(this->getCardsOnBoard()[k], ennemy);
			}
		}
	}
}

/* Destructor */
Bot::~Bot() {
	
}