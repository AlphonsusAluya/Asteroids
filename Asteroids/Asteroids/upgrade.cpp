
#include "upgrade.h"


Upgrade::Upgrade()
{

}

void Upgrade::loadContent()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/gems.png"))
	{
		std::cout << "error with large asteroid image";
	}
}

sf::Sprite Upgrade::getBody()
{
	return body; // returns body
}




void Upgrade::init(sf::Font & font)
{

	message.setFont(font); // sets the font
	message.setString("Upgrades consist of a blue pill which will be your shield \n a red pill which will increase the size of the bullet \n / R to return");
	message.setPosition(40.0f, 40.0f); // sets position of message
	message.setCharacterSize(20); // sets the character size
	message.setOutlineColor(sf::Color::Red); // sets the outline colour
	message.setFillColor(sf::Color::Black); // sets the fill colour
	message.setOutlineThickness(3.0f); // sets the thickness
}

void Upgrade::draw(sf::RenderWindow & window)
{
	window.draw(message); // draws the messages
}

void Upgrade::defense()
{

}



