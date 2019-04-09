#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"
class Player
{
	sf::Sprite sprite;
	sf::Texture texture;
	float REAL_SIZE = 0;
	MyVector3 location;
	MyVector3 velocity;
public:

	Player();
	void draw(sf::RenderWindow & window);
	sf::Sprite getBody();
	void rotate(sf::Event t_event);
	void moveLeft();
	void moveRight();
	void moveForward();
	void update();
	void moveDown();
	void checkBorders();
};