#include "MusicManager.h"

MusicManager::MusicManager(Music music) {
	this->currentMusic = music;
}

MusicManager::MusicManager() {
	this->currentMusic = Music::NONE;
}

void MusicManager::playMusic(Music music) {
		
}	

void MusicManager::stopMusic(Music music) {

}


MusicManager::~MusicManager()
{
}
