#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"
#include "playerShip.h"

class Bullets
{
	bool readyToFire = true;
	int waitCounter = 10;
	sf::RectangleShape screenArea;
	sf::Sprite bullet;
	sf::Vector2f bulletVelocity;
	sf::Texture texture;
	MyVector3 location;
	MyVector3 velocity;
	sf::Vector2f lookDirection = { 0,-1 };

	float angle = 3.14159265359 / 16.0;
	Player player;
public:
	Bullets();
	sf::Sprite getBody();
	void loadContent();
	int waitToFire();
	sf::Vector2f bulletVelocitys();

	bool getTimeToFire();
	void setBulletVelocity(float t_x, float t_y);
	void setTimeToFire(bool m_bool);
	void setWaitCounter(int t_waitCounter);
	void slowerWaitCounter(int t_slow);
	void setPos(sf::Vector2f t_pos);
	void setupBullets();
	void update();
	void fire();
	void bulletRotate();
	void draw(sf::RenderWindow &window);


};
