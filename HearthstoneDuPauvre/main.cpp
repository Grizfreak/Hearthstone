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
#include "bot.h"

void testConsole() {
	/* Test for Deck */
	Spell* spell = new Spell("Fireball", 4, 6, std::vector<Bonus>() = { Bonus::DAMAGE_BOOST }, std::vector<Target>() = { Target::DEFAULT });
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

	/* Test using a spell on a list of minion */
	std::vector<Card*> listOfMinion{ new Minion("Minion1", 1, 1, 1), new Minion("Minion2", 2, 2, 2), new Minion("Minion3", 3, 3, 3) };
	spell->useOn(listOfMinion);
	for (Card* card : listOfMinion) {
		std::cout << *card;
	}
}

int main()
{
	Spell* spell1 = new Spell("Fireball", 4, 1, std::vector<Bonus>() = { Bonus::DAMAGE_BOOST }, std::vector<Target>() = { Target::DEFAULT });
	Spell* spell2 = new Spell("Fireball", 4, 1, std::vector<Bonus>() = { Bonus::DAMAGE_BOOST }, std::vector<Target>() = { Target::DEFAULT });
	std::vector<Card*> deckForPlayer1{ new Minion("Minion1", 1, 1, 1), new Minion("Minion2", 2, 2, 2), new Minion("Minion3", 3, 3, 3), spell1 };
	std::vector<Card*> deckForPlayer2{ new Minion("Minion1", 1, 1, 1), new Minion("Minion2", 2, 2, 2), new Minion("Minion3", 3, 3, 3), spell2 };

	std::string name1 = "Player1";
	std::string name2 = "IA";

	Player player1(name1, new Deck(deckForPlayer1), sf::RectangleShape(sf::Vector2f(350.f, 140.f)),sf::Vector2f(583.f, 850.f), sf::Color::Red);
	Bot player2(name2, new Deck(deckForPlayer2), sf::RectangleShape(sf::Vector2f(350.f, 140.f)),sf::Vector2f(600.f,0.f), sf::Color::Blue);

	player1.draw();
	player1.draw();
	player2.draw();
	player2.autogame();
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
	game.displayMenu();
	return 0;
}



