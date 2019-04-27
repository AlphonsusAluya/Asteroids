#include "playerShip.h"

Player::Player()
{
	counter = 40;
	health = 100;
	if (!texture.loadFromFile("ASSETS/IMAGES/MUPMUP7UP.png"))
	{
		std::cout << "error with large asteroid image";
	}
	if (!icon.loadFromFile("ASSETS/IMAGES/menuicon.png"))
	{
		std::cout << "error with menu icon image";
	}
	sprite.setTexture(texture);
	REAL_SIZE = PLAYER_SIZE * 0.2;
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(0.15, 0.15);

	location = { 200,300,0 };
	sprite2.setTexture(icon);
}

void Player::update()
{
	counter--;
	friction();
	location = location + velocity;
	sprite.setPosition(location);
	checkBorders();
}

int Player::getHealth()
{
	return health;
}
void Player::decreaseHealth(int t_whichAsteroid)
{
	if (counter <= 0)
	{

		if (t_whichAsteroid == 1) // large asteroid
		{
			health = health - 5;
		}

		if (t_whichAsteroid == 2) // medium asteroid
		{
			health = health - 3;
		}

		if (t_whichAsteroid == 3) // medium asteroid
		{
			health = health - 1;
		}
		counter = 40;
	}
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
	window.draw(sprite2);
}

sf::Sprite Player::getBody()
{
	return sprite;
}

sf::Sprite Player::getBody2()
{
	return sprite2;
}

void Player::rotate(sf::Event t_event)
{
	MyVector3 force = { 0,0,0 };
	lookDirection.x = cos(angle);
	lookDirection.y = sin(angle);

	sprite.setRotation(angle * (180 / 3.14159265359));

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		angle -= 0.2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		angle += 0.2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		force = force + lookDirection;
		//if (speed < MAX_FORWARD_SPEED)
		//{
		//	speed += acceleration;
		//}

		sound.thePlayerSound();
	}

	//velocity.y *= speed;
	//velocity.x *= speed;
	velocity = velocity + force;
}


void Player::checkBorders()
{
	if (location.x > 800)
	{
		location.x = location.x - 840;
	}

	if (location.x < 0 - REAL_SIZE)
	{
		location.x = location.x + 840;
	}

	if (location.y >= 600)
	{
		location.y = location.y - 840;
	}

	if (location.y < 0 - REAL_SIZE)
	{
		location.y = location.y + 840;
	}
}

void Player::friction()
{
	velocity.x = velocity.x * 0.990;
	velocity.y = velocity.y * 0.990;
}

