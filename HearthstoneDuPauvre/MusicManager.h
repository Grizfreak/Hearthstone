#pragma once
#include "Music.h"


class MusicManager
{
private:
	Music currentMusic;
public:
	MusicManager(Music music);
	MusicManager();
	void playMusic(Music music);
	void stopMusic(Music music);
	~MusicManager();
};