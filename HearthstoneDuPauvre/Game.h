#pragma once
#include "Board.h"
#include "Player.h"
#include "Music Manager.h"

class Game
{
private:
	Board board;
	MusicManager musicManager;
public:
	Game(Board board, MusicManager music);
	void start();
	Player checkWin();
	~Game();
};
	