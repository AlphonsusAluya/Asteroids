#include "AsteroidsMedium.h"


AsteroidsMedium::AsteroidsMedium()
{
	if (!asteroidTexture.loadFromFile("ASSETS/IMAGES/asteroid1.png"))
	{
		std::cout << "error with large asteroid image";
	}

	sprite.setTexture(asteroidTexture); // sets the texture
	positioning();
	location = originalLocation;
}

sf::Sprite AsteroidsMedium::getMediumAsteroid()
{
	return sprite; // returns sprite
}


void AsteroidsMedium::positioning()
{
	//double randomX = 0;
	//double randomVelocityX = 0;
	//double randomVelocityY = 0;

	//randomVelocityX = rand() % 9 - 5;

	//randomVelocityY = rand() % 5 + 1;

	//randomX = rand() % 600 + 1;
	//originalLocation = { randomX,-400,0 };

	//velocity = { randomVelocityX,randomVelocityY,0 };

	double randomX = 0;
	double randomVelocityX = 0;
	double randomVelocityY = 0;

	randomVelocityX = rand() % 10 - 5; // randomizing the velocity

	randomX = rand() % 600 + 1;

	int northOrSouth = rand() % 2 + 1;

	if (northOrSouth == 1)
	{
		originalLocation = { randomX,1,0 };
		randomVelocityY = rand() % 6 + 1;
		velocity = { randomVelocityX,randomVelocityY,0 };
	}

	if (northOrSouth == 2)
	{
		originalLocation = { randomX,800,0 };
		randomVelocityY = rand() % 1 - 6;
		velocity = { randomVelocityX,randomVelocityY,0 };
	}
}

void AsteroidsMedium::move()
{
	location = location + velocity;
	sprite.setPosition(location); // moves the asteroid
}

void AsteroidsMedium::checkBorders() // checks the border
{
	if (location.x > 805 || location.x < -5)
	{
		location = originalLocation;
		wasShot = false;
	}

	if (location.y > 805)
	{
		location = originalLocation;
		wasShot = false;
	}
}

void AsteroidsMedium::update()
{
	checkBorders();
	move();
}

void AsteroidsMedium::draw(sf::RenderWindow & window)
{
	window.draw(sprite); // draws the sprite
}


