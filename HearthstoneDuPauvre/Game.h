#pragma once
#include "Board.h"
#include "Player.h"
#include "Music Manager.h"

class Game
{
private:
	Board board;
public:
	Game(Board board, MusicManager music);
	MusicManager musicManager;
	void start();
	Player checkWin();
	~Game();
};
	