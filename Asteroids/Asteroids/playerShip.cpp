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
	MyVector3 force = { 0,0,0 };
	lookDirection.x = cos(angle);
	lookDirection.y = sin(angle);
	
	sprite.setRotation(angle * (180 / 3.14159265359));

<<<<<<< HEAD
	if (t_event.key.code == sf::Keyboard::Left)
	{
		moveLeft();
		sound.thePlayerSound();
	}
=======
	
>>>>>>> f4d2c9caef884ca57be80f2ad28603c91ef874cd

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
<<<<<<< HEAD
		moveRight();
		sound.thePlayerSound();
=======
		angle -= 0.2;
>>>>>>> f4d2c9caef884ca57be80f2ad28603c91ef874cd
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
<<<<<<< HEAD
		moveForward();
		sound.thePlayerSound();
=======
		angle += 0.2;
>>>>>>> f4d2c9caef884ca57be80f2ad28603c91ef874cd
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		force = force + lookDirection;
		//if (speed < MAX_FORWARD_SPEED)
		//{
		//	speed += acceleration;
		//}
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

	if (location.y < 0 -REAL_SIZE)
	{
		location.y = location.y + 840;
	}
}

<<<<<<< HEAD
void Player::pos()
{
	sprite.setPosition(location);
=======
void Player::friction()
{
	velocity.x = velocity.x * 0.996;
	velocity.y = velocity.y * 0.996;
>>>>>>> f4d2c9caef884ca57be80f2ad28603c91ef874cd
}
