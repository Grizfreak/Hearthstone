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
#include "DeckGenerator.h"

/* Main, point where we launch the game */
int main()
{
	/* Initialize the deck generator */
	DeckGenerator deckGenerator;

	/* names of the players */
	std::string name1 = "Player1";
	std::string name2 = "IA";

	/* Generate decks for the players */
	Deck* deck1 = new Deck(*deckGenerator.generateDeck1());
	deck1->shuffle();
	deck1->shuffle();
	Deck* deck2 = new Deck(*deckGenerator.generateDeck2());
	deck2->shuffle();
	deck2->shuffle();

	/* Initialize the players*/
	Player player1(name1, deck1, sf::RectangleShape(sf::Vector2f(350.f, 140.f)),sf::Vector2f(320.f, 850.f), sf::Color::Red);
	Bot player2(name2, deck2, sf::RectangleShape(sf::Vector2f(350.f, 140.f)),sf::Vector2f(320.f,0.f), sf::Color::Blue);
	
	/* TurnManager */
	TurnManager turnManager = TurnManager(std::vector <Player*>() = { &player1, &player2 });

	/* Load background */
	sf::Texture background;
	if (!background.loadFromFile("./assets/backgrounds/background.jpg"))
	{
		std::cout << "Error while loading background" << std::endl;
		return EXIT_FAILURE;
	}
	
	/* Initialize the board */
	Board board = Board(&player1, &player2, &turnManager, &background);

	/* Initialize the game */
	Game game = Game(board, MusicManager());

	/* Launch the game */
	game.displayMenu();
	
	return 0;
}



