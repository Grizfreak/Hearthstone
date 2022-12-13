#include <string>
#include <vector>
#include <iostream>

#include "Card.h"

/* Constructor */
Card::Card(std::string name, int attack, int costMana, std::string imagePath) {
	this->name = name; 
	this->attack = attack;
	this->costMana = costMana;
	this->cardRectangle = sf::RectangleShape(sf::Vector2f(140.f, 160.f));
	this->imagePath = "./assets/cards/" + imagePath;
	this->cardTexture = sf::Texture();
	if (!this->cardTexture.loadFromFile(this->imagePath)) {
		std::cout << "Error loading card texture for card " + this->name << std::endl;
	}
	this->cardSprite = sf::Sprite(this->cardTexture);
	this->cardRectangle.setTexture(&this->cardTexture);
	if (!this->font.loadFromFile("./assets/arial.ttf")) {
		std::cout << "Error loading font for card " + this->name << std::endl;
	}
	this->costManaText = sf::Text(std::to_string(this->costMana), this->font, 40);
	this->costManaText.setFillColor(sf::Color::Blue);
	this->attackText = sf::Text(std::to_string(this->attack), this->font, 40);
	this->attackText.setFillColor(sf::Color::Red);
	this->textRectangles = std::vector<sf::Text>();
	this->textRectangles.push_back(this->costManaText);
	this->textRectangles.push_back(this->attackText);
	
}

void Card::refreshTextDatas() {
	this->costManaText.setString(std::to_string(this->costMana));
	this->attackText.setString(std::to_string(this->attack));
}

std::vector<sf::Vector2f> Card::refreshTextPositions() {
	std::vector<sf::Vector2f> positions = std::vector<sf::Vector2f>();
	positions.push_back(sf::Vector2f(this->cardRectangle.getPosition().x + 10, this->cardRectangle.getPosition().y + 10));
	positions.push_back(sf::Vector2f(this->cardRectangle.getPosition().x + 10, this->cardRectangle.getPosition().y + 130));
	return positions;
}

/* Getters */
int Card::getAttack() const
{
	return this->attack;
}

int Card::getCostMana() const
{
	return this->costMana;
}

std::string Card::getName() const
{
	return this->name;
}

std::vector<sf::Text>& Card::getTextRectangles() {
	return this->textRectangles;
}

sf::RectangleShape& Card::getCardRectangle() {
	return this->cardRectangle;
}

std::string& Card::getImagePath() {
	return this->imagePath;
}

/* Setters */
void Card::setAttack(int attack)
{
	this->attack = attack;
}

/* Desctructor */
Card::~Card() {

}

/* Redefine Operator */

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << "Card Description : \n" 
		<< "\t - Name : " << card.name << "\n"
		<< "\t - Attack : " << card.attack << "\n"
		<< "\t - Cost Mana : " << card.costMana << "\n";
	return os;
}
