#include "game.h"
#include "splash.h"

Splash::Splash()
{

}

void Splash::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Splash Screen");

	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(80);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void Splash::draw(sf::RenderWindow & window)
{
	window.draw(message);
}
