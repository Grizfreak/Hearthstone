#include "Game.h"
#include <iostream>
Game::Game(Board& board, MusicManager music)
{
	this->board = &board;
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
					this->displayGame();
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

void Game::displayGame() {
	Card* selectedCard = nullptr;
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Wouhou compile !");
	bool holdingCard = false;
	sf::Vector2i starting_position;
	sf::Vector2f current_position;
	bool isDragging = false;
	Player player1 = board->getPlayer1();
	std::vector<sf::RectangleShape*> hitboxes = { &((*this->board).getJ1cardBoard()), &player1.getPlayerHandRect() };
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
				window.close();
			}

			if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				for (int i = 0; i < player1.getHand().size(); i++)
				{
					if ((player1.getHand()[i]->getCardRectangle()).getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y) && !holdingCard)
					{
						holdingCard = true;
						selectedCard = player1.getHand()[i];
					}
				}
				if (holdingCard)
				{
					// On récupère la position de la souris
					// Avec ça on calcule la nouvelle position de la carte
					// On la centre sur le pointeur de la souris (en gros on décale la carte de la moitié de sa taille)
					current_position.x = event.mouseMove.x - 60.f;
					current_position.y = event.mouseMove.y - 70.f;
					(*selectedCard).getCardRectangle().setPosition(current_position);
				}

			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && holdingCard)
			{
				holdingCard = false;
				std::cout << "Released" << std::endl;
				if ((*hitboxes[0]).getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
				{
					std::cout << "On board" << std::endl;
					player1.placeOnBoard(selectedCard);
					std::cout << player1.getHand().size() << std::endl;
					if (player1.getCardsOnBoard().size() == 1) {
						(*selectedCard).getCardRectangle().setPosition(100, 350);
					}
					else {
						for (int i = 0; i < player1.getCardsOnBoard().size(); i++)
						{
							(player1.getCardsOnBoard()[i]->getCardRectangle()).setPosition(100.f + (i * 100.f), 350.f);
						}
					}

				}
				std::cout << "Out of bounds" << std::endl;
				if (player1.getHand().size() == 1)
				{
					(player1.getHand()[0]->getCardRectangle()).setPosition(350.f, 600.f);
				}
				else
				{
					for (int i = 0; i < player1.getHand().size(); i++)
					{
						(player1.getHand()[i]->getCardRectangle()).setPosition(350.f + (i * 100.f), 600.f);
					}
				}
			}
		}
		
		window.clear();
		window.draw((*this->board).getBackground());
		for (int i = 0; i < player1.getHand().size(); i++)
		{
			if (player1.getHand()[i] != selectedCard)
			{
				sf::RectangleShape* card = &player1.getHand()[i]->getCardRectangle();
				card->setPosition(350.f + (i * 100.f), 600.f);
				window.draw(*card);
			}
			else {
				window.draw(selectedCard->getCardRectangle());
			}

		}
		for (int i = 0; i < player1.getCardsOnBoard().size(); i++)
		{
			sf::RectangleShape* card = &player1.getCardsOnBoard()[i]->getCardRectangle();
			card->setPosition(100.f + (i * 100.f), 350.f);
			window.draw(*card);
		}
		for (int i = 0; i < hitboxes.size(); i++)
		{
			window.draw((*hitboxes[i]));
		}
		window.display();
	}
}

Game::~Game()
{
}

