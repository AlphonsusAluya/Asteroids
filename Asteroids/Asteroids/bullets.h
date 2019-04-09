#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "MyVector3.h"
#include "globalConstant.h"

class Bullets
{
	const int NUM = 10;
	bool readyToFire = true;
	int waitCounter = 10;
	sf::RectangleShape bullet[10];
public:
	Bullets();
	void fire();


};
