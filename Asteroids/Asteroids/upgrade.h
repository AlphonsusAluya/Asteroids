#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"

// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class Upgrade
{
	sf::Texture texture;
	sf::Sprite body;
public:

	Upgrade(); // default constructor

	void loadContent(); // looads contents from files
	sf::Sprite getBody(); // returns sprite
	sf::Text message;
	sf::Text pressAnyKey;
	void init(sf::Font &font);
	void draw(sf::RenderWindow &window); // draw function
	void defense();
};

