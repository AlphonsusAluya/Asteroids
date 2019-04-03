#pragma once

#include "MyVector3.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <time.h> 
#include "Game.h"
// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class Splash
{

public:

	Splash();


	sf::Text message;

	void init(sf::Font &font);
	void draw(sf::RenderWindow &window);
	void setUpMessage();
	void takeInput();
	void draw();

};

