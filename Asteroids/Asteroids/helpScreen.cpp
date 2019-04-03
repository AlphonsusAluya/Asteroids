#include "helpScreen.h"


Help::Help()
{

}

void Help::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Controls \nPick-up-sytem \nUpgrade-System");

	message.setPosition(140.0f, 120.0f);
	message.setCharacterSize(70);
	message.setOutlineColor(sf::Color::Green);
	message.setFillColor(sf::Color::White);
	message.setOutlineThickness(1.0f);

	returnMessage.setFont(font);
	returnMessage.setString("Press R to return");

	returnMessage.setPosition(200.0f, 420.0f);
	returnMessage.setCharacterSize(30);
	returnMessage.setOutlineColor(sf::Color::Red);
	returnMessage.setFillColor(sf::Color::White);
	returnMessage.setOutlineThickness(1.0f);
}

void Help::draw(sf::RenderWindow & window)
{
	window.draw(returnMessage);
	window.draw(message);
}
