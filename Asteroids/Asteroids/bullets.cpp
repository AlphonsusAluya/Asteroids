#include "bullets.h"

Bullets::Bullets()
{
	loadContent();
}

sf::Sprite Bullets::getBody()
{
	return bullet[NUMOFBULLETS];
}

void Bullets::loadContent()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/bullet16.png"))
	{
		std::cout << "error bullets";
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

}

void Bullets::fire(sf::Event t_event)
{
	if (t_event.key.code == sf::Keyboard::Space)
	{
		if (waitCounter == 0)
		{
			for (int i = 0; i < NUMOFBULLETS; i++)
			{
				if (bullet[i].getPosition().x == -2000)
				{
					bullet[i].setPosition(player.location);
					bulletVelocity[i] = player.lookDirection;
					bulletVelocity[i].x *= 2;
					bulletVelocity[i].y *= 2;

					waitCounter = 10;
					break;
				}
			}
		}

		if (waitCounter > 0)
		{
			waitCounter--;
		}
	}
}

void Bullets::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		window.draw(bullet[i]);
	}
	
}
