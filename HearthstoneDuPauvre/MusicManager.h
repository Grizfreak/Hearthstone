#pragma once
#include "MusicEnum.h"
#include <SFML/Audio.hpp>
#include <iostream>

class MusicManager
{
private:
	MusicEnum currentMusic; 
	sf::Music* ambientMusic;
	sf::Music* fxMusic;
public:
	MusicManager(MusicEnum music); // Constructor
	MusicManager(); // Constructor
	void playMusic(MusicEnum musicEnum, bool loop);// focntion to play music
	void stopMusic(MusicEnum music); // function to stop music
	~MusicManager(); // Destructor
};