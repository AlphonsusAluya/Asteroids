#include "AsteroidsMedium.h"


AsteroidsMedium::AsteroidsMedium()
{
	if (!asteroidTexture.loadFromFile("ASSETS/IMAGES/asteroid1.png"))
	{
		std::cout << "error with large asteroid image";
	}

	sprite.setTexture(asteroidTexture);
	positioning();
	location = originalLocation;
}

sf::Sprite AsteroidsMedium::getMediumAsteroid()
{
	return sprite;
}


void AsteroidsMedium::positioning()
{
	double randomX = 0;
	double randomVelocityX = 0;
	double randomVelocityY = 0;

	randomVelocityX = rand() % 9 - 5;

	randomVelocityY = rand() % 5 + 1;

	randomX = rand() % 600 + 1;
	originalLocation = { randomX,-400,0 };

	velocity = { randomVelocityX,randomVelocityY,0 };
}

void AsteroidsMedium::move()
{
	location = location + velocity;
	sprite.setPosition(location);
}

void AsteroidsMedium::checkBorders()
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

void AsteroidsMedium::update()
{
	checkBorders();
	move();
}

void AsteroidsMedium::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}


void AsteroidsMedium::wasShot()
{

}

