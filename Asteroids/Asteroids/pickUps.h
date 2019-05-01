#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"
#include "MyVector3.h"
#include "globalConstant.h"
#include <ctime>
// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class PickUps
{
	int powerUp;
public:
	PickUps();



	MyVector3 originalLocation;
	MyVector3 location;

	sf::Sprite sprite;
	sf::Texture healthPickUPTexture;
	sf::Texture moneyPickUPTexture;

	void loadContent(); // loads the content from files
	void whichPickUP(); // random power up
	void positioning(); // position function for the power ups
	int getWhichPowerUp();
	void reset();
	bool pickedUp;

	void update();
	void draw(sf::RenderWindow & window); // draw function
};
