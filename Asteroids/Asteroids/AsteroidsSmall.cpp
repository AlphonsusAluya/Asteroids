#include "AsteroidsSmall.h"



AsteroidsSmall::AsteroidsSmall()
{
	if (!asteroidTexture.loadFromFile("ASSETS/IMAGES/asteroid0.png"))
	{
		std::cout << "error with large asteroid image";
	}

	sprite.setTexture(asteroidTexture);
	positioning();

	location = originalLocation;
}


void AsteroidsSmall::positioning(MyVector3 t_location, MyVector3 t_veloctiy)
{
	location = t_location;

	int randomNum = rand() % 3 + 1;
	
	if (randomNum == 1)
	{
		double velocityX = t_veloctiy.x / 2 + 5;
	}

	if (randomNum == 2)
	{
		double velocityX = t_veloctiy.x / 2 + 5;
	}

	if (randomNum == 3)
	{
		double velocityX = t_veloctiy.x / 2 + 5;
	}
}

void AsteroidsSmall::move()
{
	location = location + velocity;
	sprite.setPosition(location);
}

void AsteroidsSmall::checkBorders()
{
	if (location.x > 805 || location.x < -5)
	{
		location = originalLocation;
	}

	if (location.y > 805)
	{
		location = originalLocation;
	}
}

void AsteroidsSmall::update()
{
	checkBorders();
	move();
}

void AsteroidsSmall::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

MyVector3 AsteroidsSmall::getVelocity()
{
	return velocity;
}

