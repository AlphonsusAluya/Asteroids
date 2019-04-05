
#include "upgrade.h"


Upgrade::Upgrade()
{

}


void Upgrade::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Upgrade screen / R to return");
	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(40);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void Upgrade::draw(sf::RenderWindow & window)
{
	window.draw(message);
}



