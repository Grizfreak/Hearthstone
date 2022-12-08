#pragma once
#include "Musicenum.h"


class MusicManager
{
private:
	MusicEnum currentMusic;
public:
	MusicManager(MusicEnum music);
	void playMusic(MusicEnum music);
	void stopMusic(MusicEnum music);
	~MusicManager();
};