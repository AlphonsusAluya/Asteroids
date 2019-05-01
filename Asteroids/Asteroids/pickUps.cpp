#include "pickUps.h"


PickUps::PickUps()
{
	loadContent();
	whichPickUP();
	positioning();
	pickedUp = false;
}

void PickUps::loadContent()
{
	if (!healthPickUPTexture.loadFromFile("ASSETS/IMAGES/gems.png"))
	{
		std::cout << "error with lhealthPickUPTexture";
	}
	sprite.setTexture(healthPickUPTexture); // set the texture
}

void PickUps::whichPickUP()
{
	 powerUp = (rand() % 2 + 1); // gives a random power

	if (powerUp == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 98)); // player facing north
	}

	if (powerUp == 2)
	{
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 98)); // player facing north
	}

}


void PickUps::positioning()
{
	double posX = (rand() % 950 + 1); // some off screen and arent drawn or updated
	double posY = (rand() % 750 + 1);

	location = { posX,posY,0 };
	sprite.setPosition(location);
}

int PickUps::getWhichPowerUp()
{
	return powerUp;
}

void PickUps::reset()
{
	whichPickUP();
	pickedUp = false;
	positioning();
}


void PickUps::update()
{
	sprite.setPosition(location); // sets position
	
}

void PickUps::draw(sf::RenderWindow & window)
{
	if (location.x < 805)
	{
		if (location.y < 605)
		{
			window.draw(sprite); // draws the sprite
		}
	}
	
}

