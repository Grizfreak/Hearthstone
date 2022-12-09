#include "Board.h"
#include <iostream>

Board::Board(Player player1, Player player2, TurnManager turnManager, sf::Texture* backgroundTexture)
{
	std::cout<< backgroundTexture->getSize().x << std::endl;
    this->player1 = player1;
	this->player2 = player2;
	this->turnManager = turnManager;
	this->j1cardBoard = sf::RectangleShape(sf::Vector2f(800.f, 140.f));
	this->j1cardBoard.setFillColor(sf::Color::Transparent);
	this->j1cardBoard.setOutlineColor(sf::Color::Red);
	this->j1cardBoard.setOutlineThickness(5.f);
	this->j1cardBoard.setPosition(100.f, 350.f);
	this->j2cardBoard = sf::RectangleShape(sf::Vector2f(800.f, 140.f));
	this->j2cardBoard.setFillColor(sf::Color::Transparent);
	this->j2cardBoard.setOutlineColor(sf::Color::Blue);
	this->j2cardBoard.setOutlineThickness(5.f);
	this->j2cardBoard.setPosition(200.f, 100.f);
	this->background = sf::Sprite(*(backgroundTexture));
}
void Board::dispawnCard(Card* card) {
	//fonction qui delete une carte du board
	

}

Player Board::getPlayer1() {
	return this->player1;
}

Player Board::getPlayer2() {
	return this->player2;
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

Board::~Board() {

}
