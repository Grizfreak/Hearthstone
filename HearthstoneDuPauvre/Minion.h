#pragma once
#include <string>
#include <vector>

#include "Card.h"
#include "Status.h"
#include "Effect.h"


class Minion : public Card
{
private:
	Status status;
	int defense;
	std::vector<Effect*> effects;  // A minion can have multiple effects 
	sf::Text defenseText;

public:
	/* Constructors */
	Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, Status status); 
	Minion(std::string name, int attack, int costMana, std::string imagePath, int defense);
	Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, Status status, std::vector<Effect*> effects);
	Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, std::vector<Effect*> effects);
	/* Methods */
	void useOn(Card* card);  // Use the effect of the minion on the card
	void useOn(std::vector<Card*> listOfCards); // Use the effect of the minion on the list of cards
	std::string statusToString(Status status) const; // Return the status of the minion as a string
	void refreshTextDatas();
	std::vector<sf::Vector2f> refreshTextPositions(); 
	/* Setters */
	void loseLife(int life); // Decrease the life of the minion
	void gainLife(int life);// Increase the life of the minion
	/* Getters */
	bool hasEffect(); // Return true if the minion has an effect
	std::vector<Effect*> getEffects();
	int getDefense(); // Return the defense of the minion
	/* Redefined operators */
	friend std::ostream& operator<<(std::ostream& os, const Minion& minion);
	~Minion(); // Destructor
};
