#include "upgradeHelp.h"


UpgradeHelp::UpgradeHelp()
{

}


void UpgradeHelp::init(sf::Font & font)
{

	message.setFont(font); // sets the font
	message.setString("Upgrade help  screen / T to return");
	message.setPosition(40.0f, 40.0f); // sets the position
	message.setCharacterSize(40); // sets the character size 
	message.setOutlineColor(sf::Color::Red); // sets the outline colour
	message.setFillColor(sf::Color::Black); // sets the fill colour
	message.setOutlineThickness(3.0f); //sets the thickness
}

void UpgradeHelp::draw(sf::RenderWindow & window)
{
	window.draw(message); // draws 
}