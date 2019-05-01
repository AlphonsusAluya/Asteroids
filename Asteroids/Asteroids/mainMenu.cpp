
#include "mainMenu.h"


MainMenu::MainMenu()
{

}


void MainMenu::init(sf::Font & font)
{

	if (!texture.loadFromFile("ASSETS/IMAGES/menu.png"))
	{
		std::cout << "error with menu image";
	}
	sprite.setTexture(texture); // sets the texture
	message.setFont(font); // sets the font 
	message.setString("Start \nHelp \nUpgrade");

	message.setPosition(200.0f, 120.0f); // sets position of message
	message.setCharacterSize(70); // sets the character size
	message.setOutlineColor(sf::Color::Black); // sets the outline colour
	message.setFillColor(sf::Color::White); // sets the fill colour
	message.setOutlineThickness(1.0f); // sets the thickness
}

void MainMenu::draw(sf::RenderWindow & window)
{
	window.draw(sprite); // draws the sprite
	window.draw(message); // draws the message
}
