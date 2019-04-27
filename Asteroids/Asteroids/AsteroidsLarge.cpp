#include "AsteroidsLarge.h"
#include "AsteroidsSmall.h"
#include "globalConstant.h"


AsteroidsLarge::AsteroidsLarge()
{
	if (!asteroidTexture.loadFromFile("ASSETS/IMAGES/asteroid2.png"))
	{
		std::cout << "error with large asteroid image";
	}

	sprite.setTexture(asteroidTexture);
	positioning();

	location = originalLocation;
}

sf::Sprite AsteroidsLarge::getLargeAsteroid()
{
	return sprite;
}

void AsteroidsLarge::positioning()
{
	double randomX = 0;
	double randomVelocityX = 0;
	double randomVelocityY = 0;
	
	randomVelocityX = rand() % 10 - 5;

	randomX = rand() % 600 + 1;

	int northOrSouth = rand() % 2 + 1;

	if (northOrSouth == 1)
	{
		originalLocation = { randomX,0,0 };
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

void AsteroidsLarge::move()
{
	location = location + velocity;
	sprite.setPosition(location);
}

void AsteroidsLarge::checkBorders()
{
	if (location.x > 805 || location.x < -5)
	{
		location = originalLocation;
	}


	if (location.y > 805 || location.y < -5)
	{
		location = originalLocation;
	}
}

void AsteroidsLarge::wasShot()
{

	location.y = originalLocation.y - 100;

}

void AsteroidsLarge::update()
{
	checkBorders();
	move();
}

void AsteroidsLarge::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

MyVector3 AsteroidsLarge::getVelocity()
{
	return velocity;
}

