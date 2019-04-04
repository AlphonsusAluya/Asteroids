#include "upgradeHelp.h"


UpgradeHelp::UpgradeHelp()
{

}


void UpgradeHelp::init(sf::Font & font)
{

	message.setFont(font);
	message.setString("Upgrade help  screen / T to return");
	message.setPosition(40.0f, 40.0f);
	message.setCharacterSize(40);
	message.setOutlineColor(sf::Color::Red);
	message.setFillColor(sf::Color::Black);
	message.setOutlineThickness(3.0f);
}

void UpgradeHelp::draw(sf::RenderWindow & window)
{
	window.draw(message);
}