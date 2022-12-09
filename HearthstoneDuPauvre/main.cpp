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

	player1.draw();
	player1.draw();
	std::cout << player1.getHand().size() << std::endl;
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
	game.displayGame();
	return 0;
    
}



