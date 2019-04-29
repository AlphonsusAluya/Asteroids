
#include "PauseMenu.h"


PauseMenu::PauseMenu()
{

}


void PauseMenu::init(sf::Font & font)
{

	sprite.setTexture(texture);
	message.setFont(font);
	message.setString("Resume \nMain Menu \nUpgrade");

	message.setPosition(200.0f, 120.0f);
	message.setCharacterSize(70);
	message.setOutlineColor(sf::Color::Black);
	message.setFillColor(sf::Color::White);
	message.setOutlineThickness(1.0f);

	rect.setPosition(150.0f, 100.0f);
	rect.setFillColor(sf::Color::Black);
	sf::Vector2f rectangleSize = { 400,400 };
	rect.setSize(rectangleSize);
}

void PauseMenu::draw(sf::RenderWindow & window)
{
	//window.draw(rect);
	window.draw(message);
}
