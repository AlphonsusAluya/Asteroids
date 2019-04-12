#pragma once

#include "MyVector3.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <time.h> 
#include "license.h"
#include "enum.h"
#include "splash.h"
#include "mainMenu.h"
#include "helpScreen.h"
#include "upgrade.h"
#include "upgradeHelp.h"
#include "pickUpSystem.h"
#include "AsteroidsLarge.h"
#include "AsteroidsMedium.h"
#include "AsteroidsSmall.h"
#include "playerShip.h"
#include "controlHelp.h"
#include "globalConstant.h"
<<<<<<< HEAD
#include "Music.h"
=======
#include "pauseMenu.h"
>>>>>>> f4d2c9caef884ca57be80f2ad28603c91ef874cd
// Andrew Bashorum And Alphonsus
// est time: 40 hours 
// act time 2 hours, +


class Game
{
	License license;
	Splash splash;
	MainMenu menu;
	Help help;

	Upgrade upgrade;
	UpgradeHelp upgradeHelp;
	PickUp pickUp;

	PauseMenu pause;
	ControlHelp controlHelp;

	Player player;
<<<<<<< HEAD
	Music sound;

=======
	bool paused = false;
>>>>>>> f4d2c9caef884ca57be80f2ad28603c91ef874cd
	AsteroidsLarge asteroidsL[MAX_ASTEROIDS];
	AsteroidsMedium mediumAsteroids[MAX_ASTEROIDS];

	AsteroidsSmall smallAsteroids[MAX_SMALL_ASTEROIDS];

	sf::Sprite backRoundSprite;
	sf::Texture backRoundTexture;
public:

	GameState currentState;
	Game();
	~Game();
	void run();
	int helpTimer = 20;
	int asteroidResetTimer = 100;
	int licenseTimer = 60;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	void setupSprite();
	void mouseClicks(sf::Event t_event, sf::RenderWindow &t_window);
	bool asteroidShot = false;
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	void changeState();
	void timer();
};
