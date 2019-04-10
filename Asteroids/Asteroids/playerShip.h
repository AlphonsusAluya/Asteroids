#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"
class Player
{
	sf::Sprite sprite;
	sf::Sprite sprite2;
	sf::Texture texture;
	sf::Texture icon;
	float REAL_SIZE = 0;
	MyVector3 location;
	MyVector3 velocity;


	float angle = 3.14159265359 / 16.0;

	float speed = 0.0f;
	float acceleration = 0.17f;
	const float MAX_FORWARD_SPEED = 40.0f;
	MyVector3 lookDirection;
public:

	Player();
	void draw(sf::RenderWindow & window);
	sf::Sprite getBody();
	sf::Sprite getBody2();
	void rotate(sf::Event t_event);
	void moveLeft();
	void moveRight();
	void moveForward();
	void update();
	void moveDown();
	void checkBorders();
	void friction();
};