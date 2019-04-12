#include "bullets.h"

Bullets::Bullets()
{
	loadContent();
}

void Bullets::loadContent()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/bullet16.png"))
	{
		std::cout << "error with large asteroid image";
	}
	bullet[NUMOFBULLETS].setTexture(texture);
}

void Bullets::setupBullets()
{
	screenArea.setSize(sf::Vector2f(800, 600));
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		bullet[i].setScale(10, 10);
		bullet[i].setPosition(-2000, -2000);
		
	}
	
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		bulletVelocity[i].x = 0;
		bulletVelocity[i].y = 0;
	}
}

void Bullets::update()
{
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		if (bullet[i].getPosition().x != -2000)
		{
			bullet[i].move(bulletVelocity[i]);
			if (screenArea.getGlobalBounds().intersects(bullet[i].getGlobalBounds()) == 2)
			{
				bullet[i].setPosition(-2000, -2000);
				bulletVelocity[i].x = 0;
				bulletVelocity[i].y = 0;
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (waitCounter == 0)
		{
			for (int i = 0; i < NUMOFBULLETS; i++)
			{
				if (bullet[i].getPosition().x == -2000)
				{
					bullet[i].setPosition(location);
				}
			}
		}
	}
}

void Bullets::fire()
{

}
