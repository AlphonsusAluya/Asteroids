
#include "PauseMenu.h"


PauseMenu::PauseMenu()
{

}


void PauseMenu::init(sf::Font & font)
{

	sprite.setTexture(texture);
	message.setFont(font);
	message.setString("Resume \nMain Menu \nUpgrade");

	message.setPosition(200.0f, 120.0f); // sets position of message
	message.setCharacterSize(70); // sets the character size
	message.setOutlineColor(sf::Color::Black); // sets the outline colour
	message.setFillColor(sf::Color::White); // sets the fill colour
	message.setOutlineThickness(1.0f); // sets the thickness

	rect.setPosition(150.0f, 100.0f); // sets the position
	rect.setFillColor(sf::Color::Black); // sets the fill colour
	sf::Vector2f rectangleSize = { 400,400 };
	rect.setSize(rectangleSize);
}

void PauseMenu::draw(sf::RenderWindow & window)
{
	//window.draw(rect);
	window.draw(message); // draws message
}
