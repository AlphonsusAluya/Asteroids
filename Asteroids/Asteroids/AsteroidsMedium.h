#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "enum.h"
#include "MyVector3.h"

// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +

class AsteroidsMedium
{

public:
	int number;
	AsteroidsMedium();
	bool wasShot = false;
	MyVector3 originalLocation;
	MyVector3 velocity;
	MyVector3 location;

	sf::Sprite sprite;
	sf::Texture asteroidTexture;


	sf::Sprite getMediumAsteroid();




	void positioning(); // sets position
	void move(); // moves the asteroids
	void checkBorders(); // checks the borders
	void update(); // updates asteroids
	void draw(sf::RenderWindow & window); // draws the asteroids 
};

