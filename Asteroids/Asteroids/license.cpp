#include "game.h"


#include "license.h"
#include "Game.h"
#include <iostream>

License::License()
{

}


void License::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Asteroids by Heskey and Alph");

	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(80);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void License::draw(sf::RenderWindow & window)
{
	window.draw(message);
}

void License::takeInput()
{
	if (sf::Keyboard::isKeyPressed)
	{
		Game::currentState = GameState::licenseScreen;
	}
}

