#pragma once

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"
//#include "game.h"

// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class License
{
public:
	License();

	sf::Sprite sprite;
	sf::Texture texture;
	sf::Text message;
	void init(sf::Font &font);
	void draw(sf::RenderWindow &window);
};