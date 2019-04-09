#include "AsteroidsLarge.h"
#include "AsteroidsSmall.h"



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
	
	randomVelocityX = rand() % 9 - 5;

	randomVelocityY = rand() % 4 + 1;

	randomX = rand() % 600 + 1;
	originalLocation = { randomX,-75,0 };

	velocity = { randomVelocityX,randomVelocityY,0 };

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

	if (location.y > 805)
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

