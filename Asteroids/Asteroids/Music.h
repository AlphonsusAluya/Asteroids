#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MyVector3.h"
#include "globalConstant.h"

class Music
{
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;

	sf::Sound playerSound;
	sf::Sound laser;
	sf::Sound menuScreenSound;

public:
	Music();
	void loadContent();
	void thePlayerSound();
	void laserSound();
	void menuSound();
	void stop();
};