
#include "license.h"


License::License()
{

}


void License::init(sf::Font & font)
{

	if (!texture.loadFromFile("ASSETS/IMAGES/planet0.png"))
	{
		std::cout << "error with large splash image";
	}
	sprite.setTexture(texture);
	message.setFont(font);
	message.setString("Asteroids \nby Heskey and Alph");

	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(60);
	message.setOutlineColor(sf::Color::White);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void License::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
	window.draw(message);
}



