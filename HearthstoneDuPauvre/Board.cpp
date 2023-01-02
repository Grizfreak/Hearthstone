#include "Board.h"
#include <iostream>

/* Constructor */
Board::Board(Player* player1, Bot* player2, TurnManager *turnManager, sf::Texture* backgroundTexture)
{
    this->player1 = player1;
	this->player2 = player2;
	this->turnManager = turnManager;
	this->j1cardBoard = sf::RectangleShape(sf::Vector2f(1050.f, 150.f));
	this->j1cardBoard.setFillColor(sf::Color::Transparent);
	this->j1cardBoard.setOutlineColor(sf::Color::Red);
	this->j1cardBoard.setOutlineThickness(5.f);
	this->j1cardBoard.setPosition(287.f, 449.f);
	this->j2cardBoard = sf::RectangleShape(sf::Vector2f(1050.f, 150.f));
	this->j2cardBoard.setFillColor(sf::Color::Transparent);
	this->j2cardBoard.setOutlineColor(sf::Color::Blue);
	this->j2cardBoard.setOutlineThickness(5.f);
	this->j2cardBoard.setPosition(300.f, 300.f);
	this->background = sf::Sprite(*(backgroundTexture));
}

/* Getters */
Player& Board::getPlayer1() {
	return *this->player1;
}

Bot& Board::getPlayer2() {
	return *this->player2;
}

sf::RectangleShape& Board::getJ1cardBoard() {
	return this->j1cardBoard;
}
sf::RectangleShape& Board::getJ2cardBoard() {
	return this->j2cardBoard;
}

sf::Sprite& Board::getBackground() {
	return this->background;
}

TurnManager& Board::getTurnManager() {
	return *this->turnManager;
}

/* Destructor */
Board::~Board() {

}
