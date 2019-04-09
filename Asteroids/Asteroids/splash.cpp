#include "game.h"
#include "splash.h"

Splash::Splash()
{

}

void Splash::init(sf::Font & font)
{

	if (!texture.loadFromFile("ASSETS/IMAGES/splash.png"))
	{
		std::cout << "error with large splash image";
	}
	sprite.setTexture(texture);

	message.setFont(font);
	message.setString("Splash Screen");

	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(80);
	message.setOutlineColor(sf::Color::White);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);

	pressAnyKey.setFont(font);
	pressAnyKey.setString("Press any key to continue");

	pressAnyKey.setPosition(80.0f, 550.0f);
	pressAnyKey.setCharacterSize(22);
	pressAnyKey.setOutlineColor(sf::Color::Black);
	pressAnyKey.setFillColor(sf::Color::White);
	pressAnyKey.setOutlineThickness(1.0f);
}

void Splash::draw(sf::RenderWindow & window)
{
	window.draw(sprite);

	window.draw(pressAnyKey);
}
