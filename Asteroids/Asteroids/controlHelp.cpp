#include "controlHelp.h"


ControlHelp::ControlHelp()
{

}

void ControlHelp::init(sf::Font & font)
{

	message.setFont(font); // sets the font 
	message.setString("the use of the arrow keys is how you will move the ship \n up down left and right the spacebar will be used to shoot \n from the ship \n to rotate the ship anticlockwise A should be pressed \n to rotate clockwise D should be pressed");

	message.setPosition(10.0f, 120.0f); // sets position of message
	message.setCharacterSize(25); // sets the character size
	message.setOutlineColor(sf::Color::Red); // sets the outline colour
	message.setFillColor(sf::Color::White); // sets the fill colour
	message.setOutlineThickness(1.0f); // sets the thickness

	returnMessage.setFont(font); // sets the font
	returnMessage.setString("Press T to return");

	returnMessage.setPosition(200.0f, 420.0f); // sets position of message
	returnMessage.setCharacterSize(18); // sets the character size
	returnMessage.setOutlineColor(sf::Color::Red); // sets the outline colour
	returnMessage.setFillColor(sf::Color::White); // sets the fill colour
	returnMessage.setOutlineThickness(1.0f); // sets the thickness
}

void ControlHelp::draw(sf::RenderWindow & window)
{
	window.draw(returnMessage);
	window.draw(message);			// draws the messages 
}