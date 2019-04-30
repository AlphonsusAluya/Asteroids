#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"
#include "playerShip.h"

class Bullets
{
	
	
	
	
	
	sf::Texture texture;
	MyVector3 location;

public:
	Bullets();
	sf::Vector2f bulletVelocity = {5, 5};
	sf::Sprite bullets;
	sf::Sprite getBody();
	void loadContent();
	int waitToFire();
	int waitCounter;
	sf::Vector2f bulletVelocitys();
	sf::Vector2f Onscreen = { -1000, -1000 };
	sf::Vector2f offScreen = { -100, -100 };
	bool readyToFire; // getting ready to fire
	bool getTimeToFire();
	void setBulletVelocity(float t_x, float t_y); // set up velocity
	void setTimeToFire(bool m_bool); // sets the actual time
	void setWaitCounter(int t_waitCounter); // wait counter
	void slowerWaitCounter(int t_slow); // iwas gonna use it for power ups like speeding up the shots
	void setPos(sf::Vector2f t_pos); // sets position
	void fire(); // checks the bullets
	void draw(sf::RenderWindow &window);


};
