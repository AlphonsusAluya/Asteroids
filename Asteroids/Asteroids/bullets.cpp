#include "bullets.h"

Bullets::Bullets()
{
	loadContent();
	bullet.setOrigin(100, 100);
}

sf::Sprite Bullets::getBody()
{
	return bullet; // returns the body 
}

void Bullets::loadContent()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/bullet16.png"))
	{
		std::cout << "error bullets";
	}
	
		bullet.setTexture(texture); // sets texture
	
	
}

int Bullets::waitToFire()
{
	return waitCounter; // wait to fire 
}

sf::Vector2f Bullets::bulletVelocitys()
{
	return bulletVelocity; // returns the velocity
}


void Bullets::setBulletVelocity(float t_x, float t_y)
{
	bulletVelocity = { t_x,t_y };
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
	t_pos = player.location;
	bullet.setPosition(t_pos); // sets position 
}

//void Bullets::setupBullets()
//{
//	screenArea.setSize(sf::Vector2f(800, 600));
//	
//		bullet.setScale(10, 10);
//		bullet.setPosition(-2000, -2000);
//		
//	
//	
//	
//		bulletVelocity.x = 0;
//		bulletVelocity.y = 0;
//	
//}
//
//void Bullets::update()
//{
//	
//		if (bullet.getPosition().x != -2000)
//		{
//			bullet.move(bulletVelocity);
//			if (screenArea.getGlobalBounds().intersects(bullet.getGlobalBounds()) == 2)
//			{
//				bullet.setPosition(-2000, -2000);
//				bulletVelocity.x = 0;
//				bulletVelocity.y = 0;
//			}
//		}
//	
//
//}

void Bullets::fire()
{
		if (bullet.getPosition().x != -2000) // checks the bullet
		{
				bullet.move(bulletVelocity);
				if (bullet.getPosition().x > 600)
				{
					bullet.setPosition(-2000, -2000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullet.getPosition().x < 0)
				{
					bullet.setPosition(-2000, -2000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullet.getPosition().y > 800)
				{
					bullet.setPosition(-2000, -2000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
				if (bullet.getPosition().y < 0)
				{
					bullet.setPosition(-2000, -2000);
					bulletVelocity = { 0.0,0.0 };
					readyToFire = true;
				}
			
		
		}
	
}

void Bullets::bulletRotate()
{
	MyVector3 force = { 0,0,0 }; // rotates it
	lookDirection.x = cos(angle);
	lookDirection.y = sin(angle);

	bullet.setRotation(angle * (180 / 3.14159265359));
}

void Bullets::draw(sf::RenderWindow & window)
{
	window.draw(bullet); // draws the bullets 
}
