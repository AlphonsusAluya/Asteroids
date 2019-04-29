#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"
#include "playerShip.h"

class Bullets
{
	
	
	sf::RectangleShape screenArea;
	
	
	sf::Texture texture;
	MyVector3 location;

	float angle = 3.14159265359 / 16.0;
	Player player;
public:
	Bullets();
	sf::Vector2f bulletVelocity;
	sf::Sprite bullets;
	sf::Sprite getBody();
	void loadContent();
	int waitToFire();
	int waitCounter = 10;
	sf::Vector2f bulletVelocitys();
	sf::Vector2f Onscreen = { -800, -600 };
	bool readyToFire = true;
	bool getTimeToFire();
	void setBulletVelocity(float t_x, float t_y);
	void setTimeToFire(bool m_bool);
	void setWaitCounter(int t_waitCounter);
	void slowerWaitCounter(int t_slow);
	void setPos(sf::Vector2f t_pos);
	void fire();
	void draw(sf::RenderWindow &window);


};
