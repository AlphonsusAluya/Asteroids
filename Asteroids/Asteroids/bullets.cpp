#include "bullets.h"

Bullets::Bullets()
{
	loadContent();
	getBody();
	bullets.setPosition(-1000, -1000);
	bulletVelocity = { 0,0 };
	waitCounter = 10;
	readyToFire = true;

}

sf::Sprite Bullets::getBody()
{
	return bullets; // returns the body 
}

void Bullets::loadContent()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/bullet32.png"))
	{
		std::cout << "error bullets";
	}
	
		bullets.setTexture(texture); // sets texture
		
	
}

int Bullets::waitToFire()
{
	return waitCounter; // wait to fire 
}

sf::Vector2f Bullets::bulletVelocitys()
{
	return bulletVelocity; // returns the velocity
}


bool Bullets::getTimeToFire()
{
	return readyToFire;		// gets the bullets ready
}

void Bullets::setBulletVelocity(float t_x, float t_y)
{
	bulletVelocity = { t_x,t_y }; // sets the velocity
}

void Bullets::setTimeToFire(bool m_bool)
{
	readyToFire = m_bool; // sets the bool for the time to fire
}


void Bullets::setWaitCounter(int t_waitCounter)
{
	waitCounter = t_waitCounter; // sets wait to fire counter
}

void Bullets::slowerWaitCounter(int t_slow)
{
	waitCounter = waitCounter - t_slow; // slows it down this will be used for a power up
}

void Bullets::setPos(sf::Vector2f t_pos)
{
	bullets.setPosition(t_pos); // sets position 
}


void Bullets::fire()
{
		if (bullets.getPosition().x == -1000) // checks the bullet
		{
				bullets.move(bulletVelocity);
				if (bullets.getPosition().x > Onscreen.x)
				{
					bullets.setPosition(-1000, -1000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullets.getPosition().x < 0)
				{
					bullets.setPosition(-1000, -1000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullets.getPosition().y > Onscreen.y)
				{
					bullets.setPosition(-1000, -1000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullets.getPosition().y < 0)
				{
					bullets.setPosition(-1000, -1000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
			
		
		}
	
}


void Bullets::draw(sf::RenderWindow & window)
{
	window.draw(getBody()); // draws the bullets 
}
