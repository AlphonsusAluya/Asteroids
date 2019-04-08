#include "player.h"

sf::Sprite Player::getBody()
{
	return body;
}

Player::Player()
{
	loadImage();
	body.setTexture(playerTexture);
	body.setScale(0.2, 0.2);
	body.setPosition(400, 300);
}

void Player::loadImage()
{
	if (!playerTexture.loadFromFile("ASSETS/IMAGES/spaceship_enemy_red.png"))
	{
		std::cout << "error";
	}
}

void Player::moveLeft()
{
	
	body.setPosition(body.getPosition().x -speed, 0);
	
}

void Player::moveRight()
{
	
	body.setPosition(body.getPosition().x + speed, 0);
	
}

void Player::moveUp()
{
	
	body.setPosition(body.getPosition().y - speed, 0);
	
}

void Player::moveDown()
{
	
	body.setPosition(body.getPosition().y + speed, 0);
	
}

void Player::dies()
{
}
