#include "playerShip.h"

Player::Player()
{
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
	sprite.setScale(0.2, 0.2);
	
	location = { 200,300,0 };
	sprite2.setTexture(icon);
}

void Player::update()
{
	friction();
	location = location + velocity;
	sprite.setPosition(location);
	checkBorders();
	if (velocity.x != 0)
	{
		lookDirection = velocity;
	}
	else if (velocity.y != 0)
	{
		lookDirection = velocity;
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
	if (t_event.key.code == sf::Keyboard::A)
	{
		sprite.rotate(-3);
	}

	if (t_event.key.code == sf::Keyboard::D)
	{
		sprite.rotate(3);
	}

	
	lookDirection.x = cos(angle);
	lookDirection.y = sin(angle);


	if (t_event.key.code == sf::Keyboard::Left)
	{
		moveLeft();
		sound.thePlayerSound();
	}

	


	if (t_event.key.code == sf::Keyboard::Right)
	{

		moveRight();
		sound.thePlayerSound();

		angle -= 0.2;

	}
	if (t_event.key.code == sf::Keyboard::Up)
	{

		moveForward();
		sound.thePlayerSound();

		angle += 0.2;

	}
	moveForward();
	sound.thePlayerSound();
	{
		moveDown();
		sound.thePlayerSound();
	}
	
}

void Player::moveLeft()
{
	MyVector3 move = { -1, 0, 0 };
	velocity = velocity + move;

}

void Player::moveRight()
{
	MyVector3 move = { 1, 0, 0 };
	velocity = velocity + move;
}

void Player::moveForward()
{
	MyVector3 move = { 0, -1, 0 };
	velocity = velocity + move;
}

void Player::moveDown()
{
	MyVector3 move = { 0, 1, 0 };
	velocity = velocity + move;
	
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

	if (location.y < 0 -REAL_SIZE)
	{
		location.y = location.y + 840;
	}
}


void Player::pos()
{
	sprite.setPosition(location);
}
void Player::friction()
{
	velocity.x = velocity.x * 0.996;
	velocity.y = velocity.y * 0.996;

}
