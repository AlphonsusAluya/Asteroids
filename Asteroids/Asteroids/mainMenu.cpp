
#include "mainMenu.h"


MainMenu::MainMenu()
{

}


void MainMenu::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Start \nHelp \nUpgrade");

	message.setPosition(200.0f, 120.0f);
	message.setCharacterSize(70);
	message.setOutlineColor(sf::Color::Green);
	message.setFillColor(sf::Color::White);
	message.setOutlineThickness(1.0f);
}

void MainMenu::draw(sf::RenderWindow & window)
{
	window.draw(message);
}
