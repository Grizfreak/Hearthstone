#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Deck.h"
#include "Minion.h"
#include "Spell.h"
#include "Game.h"


void testConsole() {
	/* Test for Deck */
	Spell* spell = new Spell("Spell1", 1, 1, TypeOfSpell::DAMAGE_BOOST);
	std::vector<Card*> deckForPlayer1{ new Minion("Minion1", 1, 1, 1), new Minion("Minion2", 2, 2, 2), new Minion("Minion3", 3, 3, 3), spell };
	Deck* deck = new Deck(deckForPlayer1);
	deck->shuffle();
	for (int i = 0; i < 4; i++) {
		std::cout << *(deck->getOneCard());
	}
	deck->shuffle();

	/* Test for a minion useOn another minion */
	Minion* minion1 = new Minion("Minion1", 1, 1, 1);
	Minion* minion2 = new Minion("Minion2", 2, 2, 2);
	minion1->useOn(minion2);
	std::cout << *minion2;
	std::cout << *minion1;
	std::cout << *spell;
}

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

	Player player1(name1, new Deck(deckForPlayer1));
		Player player2(name2, new Deck(deckForPlayer2));

	player1.draw();
	TurnManager turnManager = TurnManager(player1);
	sf::Texture background;

	if (!background.loadFromFile("./assets/backgrounds/background.jpg"))
	{
		std::cout << "Error while loading background" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Background loaded" << std::endl;
	Board board = Board(player1, player2, turnManager);
	Game game = Game(board, MusicManager());

    /////////////////////////////////////////////////////////////////////
    testConsole();
	Game game1 = Game(board, MusicManager());
	game1.displayMenu();
	
    sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML works!");
    bool holdingCard = false;
    sf::Vector2i starting_position;
    starting_position = sf::Mouse::getPosition(window);
    sf::Vector2f current_position;
	bool isDragging = false;
    /*sf::Music theme;
    if (!theme.openFromFile("Hearthstone_Heroes_of_WarCraft_Main-Title.wav")) {
        return EXIT_FAILURE;
    }
    theme.play();
	theme.setAttenuation(0.1f);*/
	if (!background.loadFromFile("./assets/backgrounds/background.jpg"))
	{
		// error...
		return EXIT_FAILURE;
	}
	sf::RectangleShape card1(sf::Vector2f(120.f, 140.f));
    sf::RectangleShape card2(sf::Vector2f(120.f, 140.f));
	sf::RectangleShape cardOnBoardBox(sf::Vector2f(800.f, 140.f));
	sf::RectangleShape cardInHand(sf::Vector2f(350.f, 140.f));
    std::vector<sf::RectangleShape*> playersCardsInHand = { &card1,&card2 };
	std::vector<sf::RectangleShape*> playersCardsOnBoard = { };
	std::vector<sf::RectangleShape*> hitboxes = { &cardOnBoardBox, &cardInHand };
    sf::Sprite s(background);
	cardOnBoardBox.setPosition(100, 350);
	cardOnBoardBox.setFillColor(sf::Color::Transparent);
	cardOnBoardBox.setOutlineColor(sf::Color::Red);
	cardOnBoardBox.setOutlineThickness(5.f);
	cardInHand.setPosition(350, 600);
	cardInHand.setFillColor(sf::Color::Transparent);
	cardInHand.setOutlineColor(sf::Color::Green);
	cardInHand.setOutlineThickness(5.f);
	card1.setPosition(350, 600);
    card2.setPosition(450, 600);
	sf::RectangleShape* selectedCard = nullptr;
    while (window.isOpen())
    {  

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window.close();

            if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
				for (int i = 0; i < playersCardsInHand.size(); i++)
				{
					if ((*playersCardsInHand[i]).getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y) && !holdingCard)
					{
                        holdingCard = true;
						selectedCard = playersCardsInHand[i];
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
				if (cardOnBoardBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					std::cout << "On board" << std::endl;
					playersCardsOnBoard.push_back(selectedCard);
					playersCardsInHand.erase(std::remove(playersCardsInHand.begin(), playersCardsInHand.end(), selectedCard), playersCardsInHand.end());
					if (playersCardsOnBoard.size() == 1) {
						(*selectedCard).setPosition(100, 350);
					}
					else {
						for (int i = 0; i < playersCardsOnBoard.size(); i++)
						{
							(*playersCardsOnBoard[i]).setPosition(100 + (i * 100), 350);
						}
					}
					
				}
				else
				{
					std::cout << "Else" << std::endl;
					if (playersCardsInHand.size() == 1)
					{
						(*playersCardsInHand[0]).setPosition(350, 600);
					}
					else
					{
						for (int i = 0; i < playersCardsInHand.size(); i++)
						{
							(*playersCardsInHand[i]).setPosition(350 + (i * 100), 600);
						}
					}
				}
			}
        }

        window.clear();
		window.draw(s);
		for (int i = 0; i < playersCardsInHand.size(); i++)
		{
			window.draw((*playersCardsInHand[i]));
		}
		for (int i = 0; i < playersCardsOnBoard.size(); i++)
		{
			window.draw((*playersCardsOnBoard[i]));
		}
		for (int i = 0; i < hitboxes.size(); i++)
		{
			window.draw((*hitboxes[i]));
		}
        window.display();
    }

    return 0;
}



