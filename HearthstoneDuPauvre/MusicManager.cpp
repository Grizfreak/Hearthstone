#include "MusicManager.h"


MusicManager::MusicManager(MusicEnum music) {
	this->currentMusic = music;
}

MusicManager::MusicManager() {
	this->currentMusic = MusicEnum::NONE;
}

void MusicManager::playMusic(MusicEnum musicEnum, bool loop) {
	sf::Music* musicToPlay= new sf::Music;
	switch (musicEnum)
	{
	case MusicEnum::MAINTITLE:
		// Open it from an audio file
		if (!(*musicToPlay).openFromFile("./assets/music/Main_Title.ogg"))
		{
			// error...
		}
		// Change some parameters
		(*musicToPlay).setVolume(25);         // reduce the volume
		(*musicToPlay).setLoop(true);         // make it loop
		// Play it
		(*musicToPlay).play();
		this->ambientMusic = musicToPlay;
		break;

	case MusicEnum::DUELMUSIC:
		if (!(*musicToPlay).openFromFile("./assets/music/Duel.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(25);
		(*musicToPlay).play();
		this->ambientMusic = musicToPlay;
		break;

	case MusicEnum::DEATHMUSIC:
		if (!(*musicToPlay).openFromFile("./assets/music/Defeat.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::WINMUSIC:
		if (!(*musicToPlay).openFromFile("./assets/music/Victory.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::RUNNINGTIME:
		if (!(*musicToPlay).openFromFile("./assets/music/Time_is_Running_Out.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::BONUS:
		if (!(*musicToPlay).openFromFile("./assets/music/Bonus.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::MONSTERATTACK:
		if (!(*musicToPlay).openFromFile("./assets/music/Monster_Attack.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::SPELL:
		if (!(*musicToPlay).openFromFile("./assets/music/Cast.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::DRAW:
		if (!(*musicToPlay).openFromFile("./assets/music/Draw.ogg"))
		{
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;
	case MusicEnum::NONE:

		default:
			break;
	}
}
	

void MusicManager::stopMusic(MusicEnum music) {
	switch (music)
	{
	case MusicEnum::NONE:
		break;
	case MusicEnum::MAINTITLE:
		this->ambientMusic->stop();
		delete this->ambientMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::DUELMUSIC:
		this->ambientMusic->stop();
		delete this->ambientMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::DEATHMUSIC:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::WINMUSIC:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::RUNNINGTIME:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::MONSTERATTACK:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::BONUS:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::SPELL:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	case MusicEnum::DRAW:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
	default:
		break;
	
	}
}


MusicManager::~MusicManager()
{
}
