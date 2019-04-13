#include "Music.h"

Music::Music()
{
	loadContent();
}

void Music::loadContent()
{
	if (!buffer.loadFromFile("ASSETS/AUDIO/engine.wav"))
	{
		std::cout << "error";
	}

	if (!buffer1.loadFromFile("ASSETS/AUDIO/laser.wav"))
	{
		std::cout << "error";
	}

	if (!buffer2.loadFromFile("ASSETS/AUDIO/menumusic2.ogg"))
	{
		std::cout << "error";
	}

	if (!buffer3.loadFromFile("ASSETS/AUDIO/Asteroid breaking.wav"))
	{
		std::cout << "error";
	}
}

void Music::thePlayerSound()
{
	playerSound.setBuffer(buffer);
	playerSound.play();
}

void Music::laserSound()
{
	laser.setBuffer(buffer1);
	laser.play();
}

void Music::menuSound()
{
	menuScreenSound.setBuffer(buffer2);
	menuScreenSound.play();
}

void Music::gamePlaySound()
{
	asteroid.setBuffer(buffer3);
	asteroid.play();
}

void Music::stop()
{
}
