#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"
#include "MyVector3.h"

// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class AsteroidsSmall
{
	
public:
	int number;
	AsteroidsSmall();

	MyVector3 originalLocation;
	MyVector3 velocity;
	MyVector3 location;

	sf::Sprite sprite;
	sf::Texture asteroidTexture;


	void positioning(MyVector3 t_location, MyVector3 t_veloctiy);
	void move();
	void checkBorders();
	void update();
	void draw(sf::RenderWindow & window);
	MyVector3 getVelocity();
};
