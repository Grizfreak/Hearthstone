#include "MusicManager.h"

/* Constructors */

/* Detailled constructor */
MusicManager::MusicManager(MusicEnum music) {
	this->currentMusic = music;
}

/* Default constructor */
MusicManager::MusicManager() {
	this->currentMusic = MusicEnum::NONE;
}

/* Method which play the music passed as paramater */
void MusicManager::playMusic(MusicEnum musicEnum, bool loop) {
	/* Initialize the object */
	sf::Music* musicToPlay= new sf::Music;
	
	switch (musicEnum)
	{
	case MusicEnum::MAINTITLE:
		// Open it from an audio file
		if (!(*musicToPlay).openFromFile("./assets/music/Main_Title.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		// Change some parameters
		(*musicToPlay).setVolume(25);         // Reduce the volume
		(*musicToPlay).setLoop(true);         // Make it loop
		// Play it
		(*musicToPlay).play();
		this->ambientMusic = musicToPlay;
		break;

	case MusicEnum::DUELMUSIC:
		if (!(*musicToPlay).openFromFile("./assets/music/Duel.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(25);
		(*musicToPlay).play();
		this->ambientMusic = musicToPlay;
		break;

	case MusicEnum::DEATHMUSIC:
		if (!(*musicToPlay).openFromFile("./assets/music/Defeat.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::WINMUSIC:
		if (!(*musicToPlay).openFromFile("./assets/music/Victory.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::RUNNINGTIME:
		if (!(*musicToPlay).openFromFile("./assets/music/Time_is_Running_Out.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::BONUS:
		if (!(*musicToPlay).openFromFile("./assets/music/Bonus.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::MONSTERATTACK:
		if (!(*musicToPlay).openFromFile("./assets/music/Monster_Attack.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::SPELL:
		if (!(*musicToPlay).openFromFile("./assets/music/Cast.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
			break;
		}
		(*musicToPlay).setVolume(50);
		(*musicToPlay).play();
		this->fxMusic = musicToPlay;
		break;

	case MusicEnum::DRAW:
		if (!(*musicToPlay).openFromFile("./assets/music/Draw.ogg"))
		{
			std::cout << "Error while loading the music" << std::endl;
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
	
/* Method used to stop the music passed as parameter */
void MusicManager::stopMusic(MusicEnum music) {
	switch (music)
	{
	/* If there is no music */
	case MusicEnum::NONE:
		break;
	
	/* If the music is an ambient music */
	case MusicEnum::MAINTITLE: case MusicEnum::DUELMUSIC:
		this->ambientMusic->stop();
		delete this->ambientMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
		
	/* If the music is a fx music */
	case MusicEnum::DEATHMUSIC: case MusicEnum::WINMUSIC: case MusicEnum::RUNNINGTIME: case MusicEnum::MONSTERATTACK: case MusicEnum::BONUS: case MusicEnum::SPELL: case MusicEnum::DRAW:
		this->fxMusic->stop();
		delete this->fxMusic;
		this->currentMusic = MusicEnum::NONE;
		break;
		
	/* Default */
	default:
		break;
	}
}

/* Destructor */
MusicManager::~MusicManager()
{
}