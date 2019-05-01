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

	message.setFont(font); // sets the font
	message.setString("Splash Screen");

	message.setPosition(40.0f, 40.0f); // sets position of message
	message.setCharacterSize(80); // sets the character size
	message.setOutlineColor(sf::Color::White); // sets the outline colour
	message.setFillColor(sf::Color::Black); // sets the fill colour
	message.setOutlineThickness(3.0f); // sets the thickness

	pressAnyKey.setFont(font); // sets the font
	pressAnyKey.setString("Press any key to continue");

	pressAnyKey.setPosition(80.0f, 550.0f); // sets position of message
	pressAnyKey.setCharacterSize(22); // sets the character size
	pressAnyKey.setOutlineColor(sf::Color::Black); // sets the outline colour
	pressAnyKey.setFillColor(sf::Color::White); // sets the fill colour
	pressAnyKey.setOutlineThickness(1.0f); // sets the thickness
}

void Splash::draw(sf::RenderWindow & window)
{
	window.draw(sprite); // draws the sprite

	window.draw(pressAnyKey); // draws the messgae
}
