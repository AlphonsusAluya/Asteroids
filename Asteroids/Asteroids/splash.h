#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"

// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class Splash
{

public:

	Splash();


	sf::Text message;
	sf::Text pressAnyKey;
	void init(sf::Font &font);
	void draw(sf::RenderWindow &window);
};

