
#include "license.h"


License::License()
{

}


void License::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Asteroids \n by Heskey and Aluya.inc");

	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(60);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void License::draw(sf::RenderWindow & window)
{
	window.draw(message);
}



