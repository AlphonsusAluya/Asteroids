#include "controlHelp.h"


ControlHelp::ControlHelp()
{

}

void ControlHelp::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("the use of the arrow keys is how you will move the ship \n up down left and right the spacebar will be used to shoot \n from the ship \n to rotate the ship anticlockwise A should be pressed \n to rotate clockwise D should be pressed");

	message.setPosition(10.0f, 120.0f);
	message.setCharacterSize(25);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::White);
	message.setOutlineThickness(1.0f);

	returnMessage.setFont(font);
	returnMessage.setString("Press T to return");

	returnMessage.setPosition(200.0f, 420.0f);
	returnMessage.setCharacterSize(18);
	returnMessage.setOutlineColor(sf::Color::Red);
	returnMessage.setFillColor(sf::Color::White);
	returnMessage.setOutlineThickness(1.0f);
}

void ControlHelp::draw(sf::RenderWindow & window)
{
	window.draw(returnMessage);
	window.draw(message);
}