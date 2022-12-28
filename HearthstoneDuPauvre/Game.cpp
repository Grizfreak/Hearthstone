#include "Game.h"
#include <iostream>
Game::Game(Board &board, MusicManager music)
{
	this->board = &board;
	music = music;
}

void Game::displayMenu()
{

	sf::RenderWindow window(sf::VideoMode(1650, 950), "Ecran de menu");
	// create a background with background2
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

	while (window.isOpen())
	{
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
			// write play on the red button
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
			// write quit on the blue button
			sf::Text text2;
			text2.setFont(font);
			text2.setString("Quit");
			text2.setCharacterSize(40);
			text2.setFillColor(sf::Color::White);
			text2.setPosition(775, 420);
			// when the mouse is on the red button, the button is green
			if (button2.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				button2.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					// close the window and start the game
					this->musicManager.stopMusic(MusicEnum::MAINTITLE);
					window.close();
					this->displayGame();
					std::cout << "play" << std::endl;
				}
			}
			// create green button
			if (button1.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				button1.setFillColor(sf::Color::Green);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					// close the window and quit the game
					this->musicManager.stopMusic(MusicEnum::MAINTITLE);
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

void Game::start()
{
	// fonction qui lance le jeu
}

Player* Game::checkWin()
{
	// fonction qui check si un joueur a gagné
	if (this->board->getPlayer1().getHealth() <= 0)
	{
		return &this->board->getPlayer2();
	}
	else if (this->board->getPlayer2().getHealth() <= 0)
	{
		return &this->board->getPlayer1();
	}
	else
	{
		return nullptr;
	}
}

void Game::displayGame()
{
	Card* selectedCard = nullptr;
	Card* cardToDisplay = nullptr;
	Card* cardWhichAttack = nullptr;
	sf::RenderWindow window(sf::VideoMode(1650, 950), "Wouhou compile !");
	bool holdingCard = false;
	bool holdingAttack = false;
	sf::Vector2i starting_position;
	sf::Vector2f current_position;
	Player* player1 = &(board->getPlayer1());
	Bot* player2 = &(board->getPlayer2());
	std::vector<sf::RectangleShape*> hitboxes = { &((*this->board).getJ1cardBoard()), &(*player1).getPlayerHandRect(), &((*this->board).getJ2cardBoard()), &(*player2).getPlayerHandRect() };
	sf::Font font;
	sf::RectangleShape buttonEndTurn = sf::RectangleShape(sf::Vector2f(150.f, 50.f));
	buttonEndTurn.setPosition(1290, 400);
	player1->getDeck().shuffle();
	player2->getDeck().shuffle();

	/* At the beginning both players have 4 cards in their hands */
	for (int j = 0; j < 4; j++) {
		player1->draw();
		player2->draw();
	}

	if (!font.loadFromFile("./assets/arial.ttf"))
	{
		std::cout << "Error while loading font" << std::endl;
	}
	this->musicManager.playMusic(MusicEnum::DUELMUSIC, true);
	while (window.isOpen())
	{
		if (this->board->getTurnManager().getCurrentPlayer() == player1) {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				{
					this->musicManager.stopMusic(MusicEnum::DUELMUSIC);
					window.close();
				}

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						// std::cout << "Mouse button pressed" << std::endl;
						std::cout << "Mouse position: " << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
						if (buttonEndTurn.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
						{
							//ENDING TURN
							std::cout << "End turn" << std::endl;
							(*player1).draw();
							std::cout << "Player 1 hand size: " << (*player1).getHand().size() << std::endl;
							this->board->getTurnManager().endturn();

						}
					}
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						for (int i = 0; i < (*player1).getHand().size(); i++)
						{
							if ((*player1).getHand()[i]->getCardRectangle().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
							{
								std::cout << "Mouse is on card" << std::endl;
								cardToDisplay = (*player1).getHand()[i];
							}
						}
						for (int i = 0; i < (*player2).getHand().size(); i++)
						{
							if ((*player2).getHand()[i]->getCardRectangle().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
							{
								std::cout << "Mouse is on card" << std::endl;
								cardToDisplay = (*player2).getHand()[i];
							}
						}
						for (int i = 0; i < (*player1).getCardsOnBoard().size(); i++)
						{
							if ((*player1).getCardsOnBoard()[i]->getCardRectangle().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
							{
								std::cout << "Mouse is on card" << std::endl;
								cardToDisplay = (*player1).getCardsOnBoard()[i];
							}
						}
						for (int i = 0; i < (*player2).getCardsOnBoard().size(); i++)
						{
							if ((*player2).getCardsOnBoard()[i]->getCardRectangle().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
							{
								std::cout << "Mouse is on card" << std::endl;
								cardToDisplay = (*player2).getCardsOnBoard()[i];
							}
						}
						if (cardToDisplay != nullptr)
						{
							std::cout << *cardToDisplay << std::endl;
						}
						
					}
				}
				if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					for (int i = 0; i < (*player1).getHand().size(); i++)
					{
						if (((*player1).getHand()[i]->getCardRectangle()).getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y) && !holdingCard)
						{
							holdingCard = true;
							selectedCard = (*player1).getHand()[i];
						}
					}
					for (int i = 0; i < (*player1).getCardsOnBoard().size(); i++)
					{
						if (((*player1).getCardsOnBoard()[i]->getCardRectangle()).getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y) && !holdingAttack)
						{
							holdingAttack = true;
							selectedCard = (*player1).getCardsOnBoard()[i];
							std::cout << "Selected card: " << *selectedCard << std::endl;
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
				if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && (holdingCard || holdingAttack))
				{

					std::cout << "Released" << std::endl;
					if ((*hitboxes[0]).getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						std::cout << "On board" << std::endl;
						if (typeid(*selectedCard) == typeid(Minion)) {
							if (player1->getCardsOnBoard().size() < 7) {
								Minion* minion = dynamic_cast<Minion*>(selectedCard);
								if (minion->hasEffect()) {
									int cpt = 0;
									for (int i = 0; i < minion->getEffects().size(); i++) {
										if (minion->getEffects()[i]->getTarget() == SINGLE) {
											cpt++;
											break;
										}
									}
									if (cpt == 0) {
										(*player1).placeOnBoard(selectedCard, player2, nullptr);
									}
									else {
										Card* cardTotouchWithEffect = waitforMouseInput(window, hitboxes, player1, player2);
										player1->placeOnBoard(selectedCard, player2, cardTotouchWithEffect);
									}
								}
								else {
									(*player1).placeOnBoard(selectedCard, player2, nullptr);
								}
							}
						}
						else if (typeid(*selectedCard) == typeid(Spell)) {
							Spell* spell = dynamic_cast<Spell*>(selectedCard);
							int cpt = 0;
							for (int i = 0; i < spell->getEffects().size(); i++) {
								if (spell->getEffects()[i]->getTarget() == SINGLE) {
									cpt++;
									break;
								}
							}
							if (cpt == 0) {
								(*player1).placeOnBoard(selectedCard, player2, nullptr);
								std::cout << "Spell used on a group of card" << std::endl;
								for (int i = 0; i < player2->getCardsOnBoard().size(); i++) {
									Minion* minion = dynamic_cast<Minion*>(player2->getCardsOnBoard()[i]);
									std::cout << "Minion: " << minion->getDefense() << std::endl;
									if (minion->getDefense() <= 0) {
										(*player2).erase(minion);
									}
								}
							}
							else {
								Card* cardTotouchWithEffect = waitforMouseInput(window, hitboxes, player1, player2);
								player1->placeOnBoard(selectedCard, player2, cardTotouchWithEffect);
								Minion* minionToTouchWithEffect = dynamic_cast<Minion*>(cardTotouchWithEffect);
								if (minionToTouchWithEffect->getDefense() <= 0) {
									(*player2).erase(minionToTouchWithEffect);
								}
							}
						}

						std::cout << (*player1).getHand().size() << std::endl;
						if ((*player1).getCardsOnBoard().size() == 1)
						{
							(*selectedCard).getCardRectangle().setPosition(((*hitboxes[0]).getPosition().x), (*hitboxes[0]).getPosition().y);
						}
						else
						{
							for (int i = 0; i < (*player1).getCardsOnBoard().size(); i++)
							{
								((*player1).getCardsOnBoard()[i]->getCardRectangle()).setPosition(((*hitboxes[0]).getPosition().x + (i * 135.f)), ((*hitboxes[0]).getPosition().y));
							}
						}
					}
					if ((*hitboxes[2]).getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						std::cout << "On board" << std::endl;
						for (int i = 0; i < (*player2).getCardsOnBoard().size(); i++)
						{
							if ((*player2).getCardsOnBoard()[i]->getCardRectangle().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
							{
								//Touch a card to attack
								std::cout << "On card : " << *(*player2).getCardsOnBoard()[i] << std::endl;
								if (selectedCard->getCanAttack())
								{
									selectedCard->useOn(player2->getCardsOnBoard()[i]);
									Minion* minion = dynamic_cast<Minion*>(selectedCard);
									Minion* ennemyMinion = dynamic_cast<Minion*>(player2->getCardsOnBoard()[i]);
									if (minion->getDefense() <= 0)
									{
										(*player1).erase(minion);
									}
									if (ennemyMinion->getDefense() <= 0)
									{
										(*player2).erase(ennemyMinion);
									}
								}
							}
						}
					}
					if ((*player2).getPlayerAvatar().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && holdingAttack)
					{
						std::cout << "On player" << std::endl;
						if (selectedCard->getCanAttack())
						{
							player1->attackPlayerWithCard(selectedCard, player2);
							Player* player = this->checkWin();
							if (player != nullptr)
							{
								if (player == player1)
								{
									std::cout << "Player 1 win" << std::endl;
								}
								else
								{
									std::cout << "Bot win" << std::endl;
								}
								window.close();
								return;
							}
						}
						
					}
					if ((*player1).getHand().size() == 1)
					{
						((*player1).getHand()[0]->getCardRectangle()).setPosition(hitboxes[1]->getPosition().x, hitboxes[1]->getPosition().y);
					}
					else
					{
						for (int i = 0; i < (*player1).getHand().size(); i++)
						{
							((*player1).getHand()[i]->getCardRectangle()).setPosition(hitboxes[1]->getPosition().x + (i * 135.f), hitboxes[1]->getPosition().y);
						}
					}
					holdingAttack = false;
					holdingCard = false;
				}
			}
		}
		else {
			player2->play(player1);
			this->board->getTurnManager().endturn();
			Player* player = this->checkWin();
			if (player != nullptr)
			{
				if (player == player1)
				{
					std::cout << "Player 1 win" << std::endl;
				}
				else
				{
					std::cout << "Bot win" << std::endl;
				}
				window.close();
				return;
			}
		}
		window.clear();
		this->drawGame(window, selectedCard, cardToDisplay, hitboxes, font, buttonEndTurn);
		this->displayTexts(window);
		window.display();
	}
}

void Game::drawGame(sf::RenderWindow &window, Card *selectedCard, Card *cardToDisplay, std::vector<sf::RectangleShape *> hitboxes, sf::Font font, sf::RectangleShape buttonEndTurn)
{
	window.draw((*this->board).getBackground());
	Player *player1 = &board->getPlayer1();
	Player *player2 = &board->getPlayer2();
	sf::RectangleShape displayCard(sf::Vector2f(300.f, 400.f));
	// Display player1 hand
	for (int i = 0; i < (*player1).getHand().size(); i++)
	{
		if ((*player1).getHand()[i] != selectedCard)
		{
			sf::RectangleShape *card = &(*player1).getHand()[i]->getCardRectangle();
			card->setPosition(hitboxes[1]->getPosition().x + (i * 135.f), hitboxes[1]->getPosition().y);
			window.draw(*card);
		}
		else
		{
			window.draw(selectedCard->getCardRectangle());
		}
	}
	// Display player1 cards on board
	for (int i = 0; i < (*player1).getCardsOnBoard().size(); i++)
	{
		sf::RectangleShape *card = &(*player1).getCardsOnBoard()[i]->getCardRectangle();
		card->setPosition(((*hitboxes[0]).getPosition().x + (i * 135.f)), ((*hitboxes[0]).getPosition().y));
		window.draw(*card);
		(*player1).getCardsOnBoard()[i]->refreshTextDatas();
		(*player1).getCardsOnBoard()[i]->refreshTextDatas();
		(*player1).getCardsOnBoard()[i]->getTextRectangles()[0].setString(std::to_string((*player1).getCardsOnBoard()[i]->getCostMana()));
		(*player1).getCardsOnBoard()[i]->getTextRectangles()[1].setString(std::to_string((*player1).getCardsOnBoard()[i]->getAttack()));
		Minion* minion = dynamic_cast<Minion*>((*player1).getCardsOnBoard()[i]);
		(*player1).getCardsOnBoard()[i]->getTextRectangles()[2].setString(std::to_string(minion->getDefense()));
		std::vector<sf::Vector2f> textPositions = (*player1).getCardsOnBoard()[i]->refreshTextPositions();
		for (int j = 0; j < (*player1).getCardsOnBoard()[i]->getTextRectangles().size(); j++)
		{
			(*player1).getCardsOnBoard()[i]->getTextRectangles()[j].setPosition(textPositions[j]);
			window.draw((*player1).getCardsOnBoard()[i]->getTextRectangles()[j]);
		}
	}
	// Display text on board
	for (int i = 0; i < (*player1).getHand().size(); i++)
	{
		std::vector<sf::Vector2f> textPositions = (*player1).getHand()[i]->refreshTextPositions();
		for (int j = 0; j < (*player1).getHand()[i]->getTextRectangles().size(); j++)
		{
			(*player1).getHand()[i]->getTextRectangles()[j].setPosition(textPositions[j]);
			window.draw((*player1).getHand()[i]->getTextRectangles()[j]);
		}
	}

	// Display player2
	for (int i = 0; i < (*player2).getHand().size(); i++)
	{
		sf::RectangleShape *card = &(*player2).getHand()[i]->getCardRectangle();
		card->setPosition(hitboxes[3]->getPosition().x + (i * 135.f), hitboxes[3]->getPosition().y);
		window.draw(*card);
	}

	// Display player2 cards on board
	for (int i = 0; i < (*player2).getCardsOnBoard().size(); i++)
	{
		sf::RectangleShape *card = &(*player2).getCardsOnBoard()[i]->getCardRectangle();
		card->setPosition(((*hitboxes[2]).getPosition().x + (i * 135.f)), ((*hitboxes[2]).getPosition().y));
		window.draw(*card);
		(*player2).getCardsOnBoard()[i]->refreshTextDatas();
		(*player2).getCardsOnBoard()[i]->getTextRectangles()[0].setString(std::to_string((*player2).getCardsOnBoard()[i]->getCostMana()));
		(*player2).getCardsOnBoard()[i]->getTextRectangles()[1].setString(std::to_string((*player2).getCardsOnBoard()[i]->getAttack()));
		Minion* minion = dynamic_cast<Minion*>((*player2).getCardsOnBoard()[i]);
		(*player2).getCardsOnBoard()[i]->getTextRectangles()[2].setString(std::to_string(minion->getDefense()));
		std::vector<sf::Vector2f> textPositions = (*player2).getCardsOnBoard()[i]->refreshTextPositions();
		for (int j = 0; j < (*player2).getCardsOnBoard()[i]->getTextRectangles().size(); j++)
		{
			(*player2).getCardsOnBoard()[i]->getTextRectangles()[j].setPosition(textPositions[j]);
			window.draw((*player2).getCardsOnBoard()[i]->getTextRectangles()[j]);
		}
	}

	for (int i = 0; i < (*player2).getHand().size(); i++)
	{
		(*player2).getHand()[i]->refreshTextPositions();
	}

	for (int i = 0; i < hitboxes.size(); i++)
	{
		window.draw((*hitboxes[i]));
	}
	window.draw(buttonEndTurn);
	if (cardToDisplay != nullptr)
	{
		sf::Texture texture = sf::Texture();
		if (!texture.loadFromFile(cardToDisplay->getImagePath()))
		{
			std::cout << "Error while loading card image" << std::endl;
		}
		displayCard.setTexture(&texture);
		displayCard.setPosition(20, 560);
		displayCard.setFillColor(sf::Color::White);
		window.draw(displayCard);
	}
	player1->getPlayerAvatar().setPosition(790, 700);
	player2->getPlayerAvatar().setPosition(790, 150);
	window.draw(player1->getPlayerAvatar());
	window.draw(player2->getPlayerAvatar());
}

void Game::displayTexts(sf::RenderWindow &window)
{
	this->board->getPlayer1().refreshTextDatas();
	this->board->getPlayer2().refreshTextDatas();
	(this->board->getPlayer1().getPlayerTexts()[1]).setPosition(1065, 870);
	this->board->getPlayer1().getPlayerTexts()[1].setString(std::to_string(this->board->getPlayer1().getCurrentMana()) + "/" + std::to_string(this->board->getPlayer1().getMaxMana()));
	sf::Text *lifeJ1Text = &this->board->getPlayer1().getPlayerTexts()[0];
	lifeJ1Text->setString(std::to_string(this->board->getPlayer1().getHealth()));
	(*lifeJ1Text).setPosition(790, 713);
	sf::Text* lifeJ2Text = &this->board->getPlayer2().getPlayerTexts()[0];
	lifeJ2Text->setString(std::to_string(this->board->getPlayer2().getHealth()));
	(*lifeJ2Text).setPosition(790, 150);
	window.draw(this->board->getPlayer1().getPlayerTexts()[1]);
	window.draw(*lifeJ1Text);
	window.draw(*lifeJ2Text);
}

Card* Game::waitforMouseInput(sf::RenderWindow& window, std::vector<sf::RectangleShape*> hitboxes, Player* player1, Player* player2) 
{
	sf::Event event;
	if (player1->getCardsOnBoard().size() > 0 || player2->getCardsOnBoard().size() > 0) {
		while (1) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if ((*hitboxes[2]).getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
						{
							std::cout << "On board" << std::endl;
							for (int i = 0; i < (*player2).getCardsOnBoard().size(); i++)
							{
								if ((*player2).getCardsOnBoard()[i]->getCardRectangle().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
								{
									std::cout << "On card : " << *(*player2).getCardsOnBoard()[i] << std::endl;
									return (*player2).getCardsOnBoard()[i];
								}
							}
						}
						if ((*hitboxes[0]).getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
						{
							std::cout << "On board" << std::endl;
							for (int i = 0; i < (*player1).getCardsOnBoard().size(); i++)
							{
								if ((*player1).getCardsOnBoard()[i]->getCardRectangle().getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
								{
									std::cout << "On card : " << *(*player1).getCardsOnBoard()[i] << std::endl;
									return (*player1).getCardsOnBoard()[i];
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		return nullptr;
	}
}

Game::~Game()
{
}
