#include "AsteroidsLarge.h"
#include "AsteroidsSmall.h"
#include "globalConstant.h"


AsteroidsLarge::AsteroidsLarge()
{
	if (!asteroidTexture.loadFromFile("ASSETS/IMAGES/asteroid2.png"))
	{
		std::cout << "error with large asteroid image";
	}

	sprite.setTexture(asteroidTexture); // sets the texture
	positioning(); // ste the positioning

	location = originalLocation;
}

sf::Sprite AsteroidsLarge::getLargeAsteroid()
{
	return sprite; // returns the sprite
}

void AsteroidsLarge::positioning() // gets the positioning of asteroids
{
	double randomX = 0;
	double randomVelocityX = 0;
	double randomVelocityY = 0;
	
	randomVelocityX = rand() % 10 - 5; // always random

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

void AsteroidsLarge::move()
{
	location = location + velocity;
	sprite.setPosition(location); // sets the location
}

void AsteroidsLarge::checkBorders()
{
	if (location.x > 810 || location.x < -10)
	{
		location = originalLocation;
		wasShot = false;
	}


	if (location.y > 810 || location.y < -10)
	{
		location = originalLocation;
		wasShot = false;
	}
}


void AsteroidsLarge::update()
{
	checkBorders();
	move();
}

void AsteroidsLarge::draw(sf::RenderWindow & window)
{
	window.draw(sprite); // draws the asteroids
}

MyVector3 AsteroidsLarge::getVelocity()
{
	return velocity; // returns velocity
}

