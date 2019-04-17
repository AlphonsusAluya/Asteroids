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
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		bullet[i].setTexture(texture);
	}
	
}

int Bullets::waitToFire()
{
	return waitCounter;
}

sf::Vector2f Bullets::bulletVelocitys()
{
	return bulletVelocity[NUMOFBULLETS];
}

bool Bullets::getTimeToFire()
{
	return readyToFire;
}

void Bullets::setBulletVelocity(float t_x, float t_y)
{
	bulletVelocity[NUMOFBULLETS] = { t_x,t_y };
}

void Bullets::setTimeToFire(bool m_bool)
{
	readyToFire = m_bool;
}

void Bullets::setWaitCounter(int t_waitCounter)
{
	waitCounter = t_waitCounter;
}

void Bullets::slowerWaitCounter(int t_slow)
{
	waitCounter = waitCounter - t_slow;
}

void Bullets::setPos(sf::Vector2f t_pos)
{
	bullet[NUMOFBULLETS].setPosition(t_pos);
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

void Bullets::fire()
{
		if (bullet[NUMOFBULLETS].getPosition().x != -2000)
		{
			for (int i = 0; i < NUMOFBULLETS; i++)
			{
				bullet[i].move(bulletVelocity[i]);
				if (bullet[i].getPosition().x < 600)
				{
					bullet[i].setPosition(-2000, -2000);
					bulletVelocity[i] = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullet[i].getPosition().x > 0)
				{
					bullet[i].setPosition(-2000, -2000);
					bulletVelocity[i] = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullet[i].getPosition().y < 800)
				{
					bullet[i].setPosition(-2000, -2000);
					bulletVelocity[i] = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullet[i].getPosition().x > 0)
				{
					bullet[i].setPosition(-2000, -2000);
					bulletVelocity[i] = { 0.0,0.0 };
					readyToFire = true;
				}
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
