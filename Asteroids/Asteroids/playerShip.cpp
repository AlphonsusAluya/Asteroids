#include "playerShip.h"

sf::Vector2f Player::getDirection()
{
	return lookDirection;
}



Player::Player()
{
	counter = 40;
	score = 340;
	health = 100;
	if (!texture.loadFromFile("ASSETS/IMAGES/MUPMUP7UP.png"))
	{
		std::cout << "error with large asteroid image";
	}
	if (!icon.loadFromFile("ASSETS/IMAGES/menuicon.png"))
	{
		std::cout << "error with menu icon image";
	}
	sprite.setTexture(texture); // sets the sprite texture
	REAL_SIZE = PLAYER_SIZE * 0.15;
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(0.15, 0.15); // makes the ship size smaller

	location = { 200,300,0 }; // sets the location at the start
	sprite2.setTexture(icon); //sets the sprite for menu icon
}

void Player::reset()
{
	counter = 40;
	score = 0;
	health = 100;
	location = { 200,300,0 };
	velocity = { 0,0,0 };
}

void Player::increaseHealth(int t_addHealth)
{
	if (counter <= 0)
	{
		health += t_addHealth;
		counter = 40; // adds health over time
	}
	
}
void Player::addScore(int t_plus)
{
	if (counter <= 0)
	{
		score = score + t_plus;
		counter = 40; // adds health over time
	}
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
	return health; // returns the health 
}

int Player::getScore()
{
	return score; // returns the score
}
void Player::decreaseHealth(int t_whichAsteroid)
{
	if (counter <= 0)
	{

		if (t_whichAsteroid == 1) // large asteroid
		{
			health = health - 15;
		}

		if (t_whichAsteroid == 2) // medium asteroid
		{
			health = health - 10;
		}

		if (t_whichAsteroid == 3) // small asteroid
		{
			health = health - 5;						// each asteroid takes off a different amount of health
		}
		counter = 40;
	}
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(sprite); // draws the sprite
	window.draw(sprite2); // draws the menu icon
}

sf::Sprite Player::getBody()
{
	return sprite; // returns the sprite
}

sf::Sprite Player::getBody2()
{
	return sprite2; // returns the menu icon
}

void Player::rotate(sf::Event t_event)
{
	MyVector3 force = { 0,0,0 };
	lookDirection.x = cos(angle);
	lookDirection.y = sin(angle);

	sprite.setRotation(angle * (180 / 3.14159265359));

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		angle -= 0.2; // rotates the ship
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		angle += 0.2; // rotates the ship
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		
		if (velocity.length() < MAX_FORWARD_SPEED) // limits when booster can be used
		{
			force = force + lookDirection; // moves forward 
		}

		sound.thePlayerSound();
	}

	velocity = velocity + force;
}


void Player::checkBorders() // checks the borders
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

void Player::friction() // so the ship slows down over time
{
	velocity.x = velocity.x * 0.990;
	velocity.y = velocity.y * 0.990;
}

void Player::changeColourToTransparent()
{
	sprite.setColor(sf::Color(255,255,255,100)); // changes to transparent colour when ship is being hit with asteroid

}

void Player::changeColourToRed()
{
	sprite.setColor(sf::Color(255, 0, 0, 100)); // changes the colour
}

void Player::changeColourToNormal()
{
	sprite.setColor(sf::Color::White); // changes the colour
}

