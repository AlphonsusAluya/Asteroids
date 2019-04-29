#include "pickUpSystem.h"


PickUp::PickUp()
{

}


void PickUp::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("The Pick up system \n \n As you destroy asteroids they drop health packets. \n \n These health packets can collected by the \n player in order to gain health. \n \n \n \n  T to return");
	message.setPosition(10.0f, 40.0f);
	message.setCharacterSize(22);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void PickUp::draw(sf::RenderWindow & window)
{
	window.draw(message);
}

