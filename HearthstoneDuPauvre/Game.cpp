#include "Game.h"
#include <iostream>
Game::Game(Board board, MusicManager music)
{
	board = board;
	music = music;
	
}

void Game::displayMenu() {

	sf::RenderWindow patate(sf::VideoMode(1024, 720), "PATATE!");
	//create a background with background2 
	sf::Texture background2;
	if (!background2.loadFromFile("./assets/backgrounds/background2.jpg"))
	{
		std::cout << "Error while loading background" << std::endl;
		return;
		
	}
	std::cout << "Background loaded" << std::endl;
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background2);
	backgroundSprite.setPosition(0, 0);
	backgroundSprite.setScale(1.0f, 1.0f);
	
	 while (patate.isOpen()) {
		sf::Event event;
		while (patate.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				patate.close();
			
			sf::RectangleShape button1(sf::Vector2f(200.f, 100.f));
			sf::RectangleShape button2(sf::Vector2f(200.f, 100.f));
			button1.setPosition(400, 400);
			button2.setPosition(400, 250);
			button1.setFillColor(sf::Color::Red);
			button2.setFillColor(sf::Color::Blue);
			//write play on the red button
			sf::Font font;
			
			if (!font.loadFromFile("./assets/arial.ttf"))
			{
				
			}

			sf::Text text;
			text.setFont(font);
			text.setString("Play");
			text.setCharacterSize(40);
			text.setFillColor(sf::Color::White);
			text.setPosition(465, 270);
			//write quit on the blue button
			sf::Text text2;
			text2.setFont(font);
			text2.setString("Quit");
			text2.setCharacterSize(40);
			text2.setFillColor(sf::Color::White);
			text2.setPosition(465, 420);
			//when the mouse is on the red button, the button is green
			if (sf::Mouse::getPosition(patate).x > 400 && sf::Mouse::getPosition(patate).x < 600 && sf::Mouse::getPosition(patate).y > 250 && sf::Mouse::getPosition(patate).y < 350)
			{
				button2.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//close the window and start the game
					patate.close();
					std::cout << "play" << std::endl;
				}
			}
			//create green button
			if (sf::Mouse::getPosition(patate).x > 400 && sf::Mouse::getPosition(patate).x < 600 && sf::Mouse::getPosition(patate).y > 400 && sf::Mouse::getPosition(patate).y < 500)
			{
				button1.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//close the window and quit the game
					patate.close();
					std::cout << "quit" << std::endl;
				}
			}
			

			patate.draw(backgroundSprite);
			patate.draw(button1);
			patate.draw(button2);
			patate.draw(text);
			patate.draw(text2);
			patate.display();
			
			


		}


	}
}

void Game::start() {
	//fonction qui lance le jeu
}

Player* Game::checkWin() {
	//fonction qui check si un joueur a gagné
	return NULL;
	
}

Game::~Game()
{
}

