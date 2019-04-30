#pragma once

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"
//#include "game.h"

// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class GameOver
{
public:
	GameOver();
	bool won = false;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture LTexture;
	sf::Text message;
	sf::Text Lmessage;


	void init(sf::Font &font);
	void draw(sf::RenderWindow &window);

};
