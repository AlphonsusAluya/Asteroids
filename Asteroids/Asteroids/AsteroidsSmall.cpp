#include "AsteroidsSmall.h"



AsteroidsSmall::AsteroidsSmall()
{
	if (!asteroidTexture.loadFromFile("ASSETS/IMAGES/asteroid0.png"))
	{
		std::cout << "error with large asteroid image";
	}

	sprite.setTexture(asteroidTexture);
	originalLocation = { 1000,1000,1000 };

	location = originalLocation;
}


void AsteroidsSmall::positioning(MyVector3 t_location, MyVector3 t_veloctiy)
{
	location = t_location;
	int randomNum = rand() % 3 + 1;



	velocity.x = t_veloctiy.x + rand() % 3 + 1;

	velocity.y = t_veloctiy.y + rand() % 2 - 1;
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
		
	}

	if (location.y > 805)
	{
		
	}
}

void AsteroidsSmall::update()
{
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

