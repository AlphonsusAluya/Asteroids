#include "playerShip.h"

Player::Player()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/spaceship_enemy_red.png"))
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
	friction();
	location = location + velocity;
	sprite.setPosition(location);
	checkBorders();
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

	lookDirection.x = cos(angle);
	lookDirection.y = sin(angle);
	
	sprite.setRotation(angle * (180 / 3.14159265359));

	velocity = lookDirection;
	// get keyboard input.


	// get keyboard input.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		angle -= 0.25;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		angle += 0.25;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (speed < MAX_FORWARD_SPEED)
		{
			speed += acceleration;
		}
	}


	velocity.y *= speed;
	velocity.x *= speed;
}


void Player::checkBorders()
{
	if (location.x > 800)
	{
		location.x = location.x - 1080;
	}

	if (location.x < 0 - REAL_SIZE)
	{
		location.x = location.x + 1080;
	}

	if (location.y >= 600)
	{
		location.y = location.y - 880;
	}

	if (location.y < 0 -REAL_SIZE)
	{
		location.y = location.y + 880;
	}
}

void Player::friction()
{
	velocity.x = velocity.x * 0.996;
	velocity.y = velocity.y * 0.996;
}
