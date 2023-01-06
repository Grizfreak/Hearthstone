#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Effect.h"

/* Class card used to symbolise the card of the game */
class Card
{
/* Attributes */
private:
	int attack;
	int costMana;
	std::string name;
	std::string imagePath;
	sf::Sprite cardSprite;
	sf::Texture cardTexture;
	sf::Text costManaText;
	sf::Text attackText;
	bool canAttack;
	bool divineShield;
	
protected:
	sf::RectangleShape cardRectangle;
	sf::Font font;

protected:
	std::vector<sf::Text> textRectangles;

/* Methods */
public:
	/* Constructor */
	Card(std::string name, int attack, int costMana, std::string imagePath);
	/* Methods */
	/* Method to know if it can be use */
	virtual void useOn(Card *card) = 0;
	virtual void useOn(std::vector<Card*> listOfCards) = 0;
	virtual void refreshTextDatas();
	/* set the attack */
	virtual std::vector<sf::Vector2f> refreshTextPositions();
	/* Getters */
	/* Return if he get the attack */
	int getAttack() const;
	/* Return the cost mana */
	int getCostMana() const;
	/* Return the name */
	std::string getName() const;
	/* Method to get the text of the image */
	std::vector<sf::Text>& getTextRectangles();
	/* Method to get the hitbox of the card */
	sf::RectangleShape& getCardRectangle();
	/* Method to get the path of the image */
	std::string& getImagePath();
	/* Return if yes or no the target can attack */
	bool getCanAttack() const;
	/* Return if yes or no the target have the divine shield */
	bool getDivineShield() const;
	/* Setters */
	/* set the attack */
	void setAttack(int attack);
	/* set if he can attack */
	void setCanAttack(bool canAttack);
	/* set if he have the divine shield */
	void setDivineShield(bool divineShield);
	/* Destructor */
	~Card();
	/* Redefine Operator */
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};