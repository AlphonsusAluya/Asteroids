#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"

// Alphonsus and Andrew Bashorum
// est time: 40 hours 
// act time 2 hours, +

class ControlHelp
{
public:

	ControlHelp();

	sf::Text returnMessage;
	sf::Text message;
	void init(sf::Font &font);
	void draw(sf::RenderWindow &window);
};