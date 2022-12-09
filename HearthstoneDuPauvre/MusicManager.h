#pragma once
#include "MusicEnum.h"
#include <SFML/Audio.hpp>


class MusicManager
{
private:
	MusicEnum currentMusic;
	sf::Music* ambientMusic;
	sf::Music* fxMusic;
public:
	MusicManager(MusicEnum music);
	MusicManager();
	void playMusic(MusicEnum musicEnum, bool loop);
	void stopMusic(MusicEnum music);
	~MusicManager();
};