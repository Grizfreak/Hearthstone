#include "Game.h"

Game::Game(Board board, MusicManager music)
{
	board = board;
	music = music;
}

void Game::start() {
	//fonction qui lance le jeu
}

Player Game::checkWin() {
	//fonction qui check si un joueur a gagné
}

Game::~Game()
{
}

