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


	location = { 200,300,0 };
	sprite.setScale(0.2, 0.2);

	REAL_SIZE = PLAYER_SIZE * 0.2;
	sprite.setTexture(texture);
	sprite2.setTexture(icon);

}

void Player::update()
{
	location = location + velocity;
	sprite.setOrigin(location.x - REAL_SIZE / 2, location.y - REAL_SIZE / 2);
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
	if (t_event.key.code == sf::Keyboard::A)
	{
		sprite.rotate(-3);
	}

	if (t_event.key.code == sf::Keyboard::D)
	{
		sprite.rotate(3);
	}

	if (t_event.key.code == sf::Keyboard::Left)
	{
		moveLeft();
	}

	if (t_event.key.code == sf::Keyboard::Right)
	{
		moveRight();
	}

	if (t_event.key.code == sf::Keyboard::Up)
	{
		moveForward();
	}

	if (t_event.key.code == sf::Keyboard::Down)
	{
		moveDown();
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
	if (location.x > 950)
	{
		location.x = location.x - 1080;
	}

	if (location.x < -150)
	{
		location.x = location.x + 1080;
	}

	if (location.y > 750)
	{
		location.y = location.y - 880;
	}

	if (location.y < -150)
	{
		location.y = location.y + 880;
	}
}
