#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Deck.h"
#include "Minion.h"
#include "Spell.h"
#include "Game.h"
#include "Board.h"

int main()
{
	Spell* spell = new Spell("Spell1", 1, 1, TypeOfSpell::DAMAGE_BOOST);
	std::vector<Card*> deckForPlayer1{ new Minion("Minion1", 1, 1, 1),
		new Minion("Minion2", 2, 2, 2),
		new Minion("Minion3", 3, 3, 3),
		spell };

	std::vector<Card*> deckForPlayer2{ new Minion("Minion1", 1, 1, 1),
		new Minion("Minion2", 2, 2, 2),
		new Minion("Minion3", 3, 3, 3),
		spell };

	std::string name1 = "Player1";
	std::string name2 = "IA";

	Player player1(name1, new Deck(deckForPlayer1), sf::RectangleShape(sf::Vector2f(350.f, 140.f)));
	Player player2(name2, new Deck(deckForPlayer2), sf::RectangleShape(sf::Vector2f(200.f, 140.f)));

	TurnManager turnManager = TurnManager(player1);
	sf::Texture background;

	if (!background.loadFromFile("./assets/backgrounds/background.jpg"))
	{
		std::cout << "Error while loading background" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Background loaded" << std::endl;
	Board board = Board(player1, player2, turnManager, &background);
	Game game = Game(board, MusicManager());
	sf::RectangleShape* selectedCard = nullptr;
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Wouhou ça compile !");
	bool holdingCard = false;
	sf::Vector2i starting_position;
	sf::Vector2f current_position;
	bool isDragging = false;
	std::vector<sf::RectangleShape*> hitboxes = { &board.getJ1cardBoard(), &player1.getPlayerHandRect() };
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window.close();

			if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				for (int i = 0; i < player1.getHand().size(); i++)
				{
					if ((player1.getHand()[i]->getCardRectangle()).getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y) && !holdingCard)
					{
						holdingCard = true;
						selectedCard = &player1.getHand()[i]->getCardRectangle();
					}
				}
				if (holdingCard)
				{
					current_position.x = event.mouseMove.x - 60.f;
					current_position.y = event.mouseMove.y - 70.f;
					(*selectedCard).setPosition(current_position);
				}

			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && holdingCard)
			{
				holdingCard = false;
				std::cout << "Released" << std::endl;
				if ((*hitboxes[0]).getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
				{
					std::cout << "On board" << std::endl;
					if (player1.getHand().size() == 1) {
						(*selectedCard).setPosition(100, 350);
					}
					else {
						for (int i = 0; i < player1.getCardsOnBoard().size(); i++)
						{
							(player1.getCardsOnBoard()[i]->getCardRectangle()).setPosition(100.f + (i * 100.f), 350.f);
						}
					}

				}
				else
				{
					std::cout << "Else" << std::endl;
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
		}
		window.clear();
		std::cout << "Drawing" << std::endl;
		window.draw(board.getBackground());
		for (int i = 0; i < player1.getHand().size(); i++)
		{
			window.draw((player1.getHand()[i]->getCardRectangle()));
		}
		for (int i = 0; i < player1.getHand().size(); i++)
		{
			window.draw((player1.getHand()[i]->getCardRectangle()));
		}
		for (int i = 0; i < hitboxes.size(); i++)
		{
			window.draw((*hitboxes[i]));
		}
		window.display();
	}
	return 0;
    
}



