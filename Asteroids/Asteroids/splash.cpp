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

	pressAnyKey.setFont(font);
	pressAnyKey.setString("Press any key to continue");

	pressAnyKey.setPosition(80.0f, 500.0f);
	pressAnyKey.setCharacterSize(20);
	pressAnyKey.setOutlineColor(sf::Color::Red);
	pressAnyKey.setFillColor(sf::Color::Black);
	pressAnyKey.setOutlineThickness(1.0f);
}

void Splash::draw(sf::RenderWindow & window)
{
	window.draw(message);
	window.draw(pressAnyKey);
}
