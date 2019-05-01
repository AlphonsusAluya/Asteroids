#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"
#include "Music.h"

class Player
{
	Music sound;
	int counter;
	sf::Sprite sprite2; 
	sf::Texture texture;
	sf::Texture icon;
	
	
	int health;
	int score;


	float angle = 3.14159265359 / 16.0; // angle for rotation

	float speed = 0.0f;
	float acceleration = 0.17f;
	const float MAX_FORWARD_SPEED = 9.888f;
	
public:
	float REAL_SIZE;
	sf::Sprite sprite; // player ship
	MyVector3 location;
	MyVector3 velocity;
	sf::Vector2f lookDirection = { 0,-1 };
	sf::Vector2f getDirection();
	Player();
	void draw(sf::RenderWindow & window); // draw function
	sf::Sprite getBody();
	sf::Sprite getBody2();
	void rotate(sf::Event t_event);
	void update();
	void moveDown();
	void checkBorders(); // check the borders
	void decreaseHealth(int t_whichAsteroid);
	int getHealth(); // returns health
	int getScore(); // returns the score
	void pos();
	void addScore(int t_plus); // adds score overtime
	void friction(); // slows down the ship overtime
	void changeColourToTransparent(); // if hit it changes the colour
	void changeColourToRed();
	void changeColourToNormal();
	void increaseHealth(int t_addHealth); // adds health
	void reset();
};