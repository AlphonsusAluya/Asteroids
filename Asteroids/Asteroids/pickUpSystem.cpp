#include "pickUpSystem.h"


PickUp::PickUp()
{

}


void PickUp::init(sf::Font & font)
{

	message.setFont(font); // sets the font
	message.setString("The Pick up system \n \n As you destroy asteroids they drop health packets. \n \n These health packets can collected by the \n player in order to gain health. \n \n \n \n  T to return");
	message.setPosition(10.0f, 40.0f); // sets the position of the message
	message.setCharacterSize(22); // sets the character size for the message
	message.setOutlineColor(sf::Color::Red); // sets the outline colour
	message.setFillColor(sf::Color::Black); // sets the fill colour
	message.setOutlineThickness(3.0f); // sets the thickness
}

void PickUp::draw(sf::RenderWindow & window)
{
	window.draw(message); // draws the message
}

