#include "Game.h"
#include <iostream>
Game::Game(Board& board, MusicManager music)
{
	this->board = &board;
	music = music;
	
}

void Game::displayMenu() {

	sf::RenderWindow window(sf::VideoMode(1650, 950), "Ecran de menu");
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
	this->musicManager.playMusic(MusicEnum::MAINTITLE, true);
	
	 while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
			
			sf::RectangleShape button1(sf::Vector2f(200.f, 100.f));
			sf::RectangleShape button2(sf::Vector2f(200.f, 100.f));
			button1.setPosition(725, 400);
			button2.setPosition(725, 250);
			button1.setFillColor(sf::Color::Red);
			button2.setFillColor(sf::Color::Blue);
			//write play on the red button
			sf::Font font;
			
			if (!font.loadFromFile("./assets/arial.ttf"))
			{
				std::cout << "Error while loading font" << std::endl;
			}

			sf::Text text;
			text.setFont(font);
			text.setString("Play");
			text.setCharacterSize(40);
			text.setFillColor(sf::Color::White);
			text.setPosition(775, 270);
			//write quit on the blue button
			sf::Text text2;
			text2.setFont(font);
			text2.setString("Quit");
			text2.setCharacterSize(40);
			text2.setFillColor(sf::Color::White);
			text2.setPosition(775, 420);
			//when the mouse is on the red button, the button is green
			if (button2.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				button2.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//close the window and start the game
					this->musicManager.stopMusic(MusicEnum::MAINTITLE);
					window.close();
					this->displayGame();
					std::cout << "play" << std::endl;
				}
			}
			//create green button
			if (button1.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				button1.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//close the window and quit the game
					window.close();
					std::cout << "quit" << std::endl;
				}
			}
			

			window.draw(backgroundSprite);
			window.draw(button1);
			window.draw(button2);
			window.draw(text);
			window.draw(text2);
			window.display();
			
			


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
	sf::RenderWindow window(sf::VideoMode(1650, 950), "Wouhou compile !");
	bool holdingCard = false;
	sf::Vector2i starting_position;
	sf::Vector2f current_position;
	bool isDragging = false;
	Player player1 = board->getPlayer1();
	Player player2 = board->getPlayer2();
	std::vector<sf::RectangleShape*> hitboxes = { &((*this->board).getJ1cardBoard()), &player1.getPlayerHandRect(), &((*this->board).getJ2cardBoard()), &player2.getPlayerHandRect() };
	sf::Font font;
	sf::Text manaText;
	sf::Text lifeJ1Text;
	sf::Text lifeJ2Text;
	sf::RectangleShape buttonEndTurn = sf::RectangleShape(sf::Vector2f(150.f, 50.f));
	buttonEndTurn.setPosition(1290, 400);
	manaText.setFont(font);
	lifeJ1Text.setFont(font);
	lifeJ2Text.setFont(font);
	if (!font.loadFromFile("./assets/arial.ttf"))
	{
		std::cout << "Error while loading font" << std::endl;
	}
	this->musicManager.playMusic(MusicEnum::DUELMUSIC, true);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					//std::cout << "Mouse button pressed" << std::endl;
					std::cout << "Mouse position: " << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
					//std::cout << "Card position: " << player1.getPlayerHand()[0].getCardSprite().getPosition().x << " " << player1.getPlayerHand()[0].getCardSprite().getPosition().y << std::endl;
					//std::cout << "Card size: " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().width << " " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().height << std::endl;
					//std::cout << "Card position: " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().left << " " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().top << std::endl;
					//std::cout << "Card position: " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().left + player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().width << " " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().top + player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().height << std::endl;
					//std::cout << "Card position: " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().left + player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().width << " " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().top + player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().height << std::endl;
					//std::cout << "Card position: " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().left + player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().width << " " << player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().top + player1.getPlayerHand()[0].getCardSprite().getGlobalBounds().height << std::endl;

				}
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
						(*selectedCard).getCardRectangle().setPosition(((*hitboxes[0]).getPosition().x), (*hitboxes[0]).getPosition().y);
					}
					else {
						for (int i = 0; i < player1.getCardsOnBoard().size(); i++)
						{
							(player1.getCardsOnBoard()[i]->getCardRectangle()).setPosition(((*hitboxes[0]).getPosition().x + (i * 100.f)), ((*hitboxes[0]).getPosition().y));
						}
					}

				}
				std::cout << "Out of bounds" << std::endl;
				if (player1.getHand().size() == 1)
				{
					(player1.getHand()[0]->getCardRectangle()).setPosition(hitboxes[1]->getPosition().x, hitboxes[1]->getPosition().y);
				}
				else
				{
					for (int i = 0; i < player1.getHand().size(); i++)
					{
						(player1.getHand()[i]->getCardRectangle()).setPosition(hitboxes[1]->getPosition().x + (i * 100.f), hitboxes[1]->getPosition().y);
					}
				}
			}
		}
		
		window.clear();
		window.draw((*this->board).getBackground());
		//Display player1
		for (int i = 0; i < player1.getHand().size(); i++)
		{
			if (player1.getHand()[i] != selectedCard)
			{
				sf::RectangleShape* card = &player1.getHand()[i]->getCardRectangle();
				card->setPosition(hitboxes[1]->getPosition().x + (i * 100.f), hitboxes[1]->getPosition().y);
				window.draw(*card);
			}
			else {
				window.draw(selectedCard->getCardRectangle());
			}

		}
		for (int i = 0; i < player1.getCardsOnBoard().size(); i++)
		{
			sf::RectangleShape* card = &player1.getCardsOnBoard()[i]->getCardRectangle();
			card->setPosition(((*hitboxes[0]).getPosition().x + (i * 100.f)), ((*hitboxes[0]).getPosition().y));
			window.draw(*card);
		}
		
		// Display player2
		for (int i = 0; i < player2.getHand().size(); i++)
		{
				sf::RectangleShape* card = &player2.getHand()[i]->getCardRectangle();
				card->setPosition(hitboxes[3]->getPosition().x + (i * 100.f), hitboxes[3]->getPosition().y);
				window.draw(*card);

		}
		for (int i = 0; i < player2.getCardsOnBoard().size(); i++)
		{
			sf::RectangleShape* card = &player2.getCardsOnBoard()[i]->getCardRectangle();
			card->setPosition(((*hitboxes[2]).getPosition().x + (i * 100.f)), ((*hitboxes[2]).getPosition().y));
			window.draw(*card);
		}
		for (int i = 0; i < hitboxes.size(); i++)
		{
			window.draw((*hitboxes[i]));
		}
		std::string mana = std::to_string(player1.getCurrentMana());
		std::string maxMana = std::to_string(player1.getMaxMana());
		manaText.setString(mana + "/" + maxMana);
		manaText.setCharacterSize(40);
		manaText.setFillColor(sf::Color::White);
		manaText.setPosition(1065, 870);
		
		lifeJ1Text.setString(std::to_string(player1.getHealth()));
		lifeJ1Text.setCharacterSize(40);
		lifeJ1Text.setFillColor(sf::Color::White);
		lifeJ1Text.setPosition(790, 713);
		
		lifeJ2Text.setString(std::to_string(this->board->getPlayer2().getHealth()));
		lifeJ2Text.setCharacterSize(40);
		lifeJ2Text.setFillColor(sf::Color::White);
		lifeJ2Text.setPosition(790, 150);
		window.draw(manaText);
		window.draw(lifeJ1Text);
		window.draw(lifeJ2Text);
		window.draw(buttonEndTurn);
		window.display();
	}
}

Game::~Game()
{
}

