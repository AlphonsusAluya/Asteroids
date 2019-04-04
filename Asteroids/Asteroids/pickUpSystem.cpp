#include "pickUpSystem.h"


PickUp::PickUp()
{

}


void PickUp::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("pick up help  screen / T to return");
	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(40);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void PickUp::draw(sf::RenderWindow & window)
{
	window.draw(message);
}