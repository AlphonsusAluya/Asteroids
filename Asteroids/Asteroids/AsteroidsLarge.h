#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"
#include "MyVector3.h"
#include <ctime>
// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class AsteroidsLarge
{

public:
	int number;
	AsteroidsLarge();

	MyVector3 originalLocation;
	MyVector3 velocity;
	MyVector3 location;

	sf::Sprite sprite;
	sf::Texture asteroidTexture;


	sf::Sprite getLargeAsteroid();

	void wasShot();


	void positioning();
	void move();
	void checkBorders();
	void update();
	void draw(sf::RenderWindow & window);
	MyVector3 getVelocity();
};

