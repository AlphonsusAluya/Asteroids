#pragma once

#include "MyVector3.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <time.h> 
#include "Game.h"
#include "enum.h"
#include "license.h"
// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +


class Game
{
public:
	
	static GameState currentState;
	Game();
	~Game();
	void run();
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	void setupSprite();

	
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	License license;
};
