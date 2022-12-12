#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Effect.h"

class Card
{
private:
	int attack;
	int costMana;
	std::string name;
	std::string imagePath;
	sf::Sprite cardSprite;
	sf::Texture cardTexture;
	sf::Text costManaText;
	sf::Text attackText;
	
protected:
	sf::RectangleShape cardRectangle;
	sf::Font font;

protected:
	std::vector<sf::Text> textRectangles;

public:
	/* Constructor */
	Card(std::string name, int attack, int costMana, std::string imagePath);
	/* Methods */
	virtual void useOn(Card *card) = 0;
	virtual void useOn(std::vector<Card*> listOfCards) = 0;
	virtual void refreshTextDatas();
	virtual std::vector<sf::Vector2f> refreshTextPositions();
	/* Getters */
	int getAttack() const;
	int getCostMana() const;
	std::string getName() const;
	std::vector<sf::Text>& getTextRectangles();
	sf::RectangleShape& getCardRectangle();
	std::string& getImagePath();
	/* Setters */
	void setAttack(int attack);
	/* Destructor */
	~Card();
	/* Redefine Operator */
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};