#include "gameOver.h"


GameOver::GameOver()
{

}


void GameOver::init(sf::Font & font)
{

	if (!texture.loadFromFile("ASSETS/IMAGES/menu.png"))
	{
		std::cout << "error with menu image";
	}

	if (!LTexture.loadFromFile("ASSETS/IMAGES/planet0.png"))
	{
		std::cout << "error with menu image";
	}
	sprite.setTexture(texture);
	message.setFont(font);
	message.setString("Restart \nHelp \nUpgrade \n YOU WON");

	message.setPosition(200.0f, 120.0f);
	message.setCharacterSize(70);
	message.setOutlineColor(sf::Color::Black);
	message.setFillColor(sf::Color::Red);
	message.setOutlineThickness(1.0f);

	Lmessage.setFont(font);
	Lmessage.setString("Restart \nHelp \nUpgrade \n  YOU LOST");

	Lmessage.setPosition(200.0f, 120.0f);
	Lmessage.setCharacterSize(70);
	Lmessage.setOutlineColor(sf::Color::Black);
	Lmessage.setFillColor(sf::Color::Red);
	Lmessage.setOutlineThickness(1.0f);
}

void GameOver::draw(sf::RenderWindow & window)
{
	if (won == true)
	{
		window.draw(sprite);
		window.draw(message);
	}

	if (won == false)
	{
		sprite.setTexture(LTexture);
		window.draw(sprite);
		window.draw(Lmessage);
	}
	
}
