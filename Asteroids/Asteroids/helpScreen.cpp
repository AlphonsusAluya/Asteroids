#include "helpScreen.h"


Help::Help()
{

}

void Help::init(sf::Font & font)
{

	message.setFont(font); // sets the font
	message.setString("Controls \nPick-up-sytem \nUpgrade-System");

	message.setPosition(140.0f, 120.0f); // sets position of message
	message.setCharacterSize(70); // sets the character size
	message.setOutlineColor(sf::Color::Green); // sets the outline colour
	message.setFillColor(sf::Color::White); // sets the fill colour
	message.setOutlineThickness(1.0f); // sets the thickness

	returnMessage.setFont(font); // sets the font
	returnMessage.setString("Press R to return");

	returnMessage.setPosition(200.0f, 420.0f); // sets position of message
	returnMessage.setCharacterSize(30); // sets the character size
	returnMessage.setOutlineColor(sf::Color::Red); // sets the outline colour
	returnMessage.setFillColor(sf::Color::White); // sets the fill colour
	returnMessage.setOutlineThickness(1.0f); // sets the thickness
}

void Help::draw(sf::RenderWindow & window)
{
	window.draw(returnMessage);
	window.draw(message);		// draws the messages
}
