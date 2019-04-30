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
#include "Music.h"
#include "pauseMenu.h"
#include "bullets.h"
#include "pickUps.h"

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
	Music sound;
	Bullets bullet[NUMOFBULLETS];
	PickUps pickUps[MAX_PICK_UPS];

	sf::Text healthMessage; // text used for message on screen
	sf::Text scoreMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo

	bool paused = false;
	bool anotherRound = false;
	bool gameOver = false;

	bool asteroidSlow = false;
	bool asteroidNormal = true;

	AsteroidsLarge asteroidsL[MAX_ASTEROIDS];
	AsteroidsMedium mediumAsteroids[MAX_ASTEROIDS];

	AsteroidsSmall smallAsteroids[MAX_SMALL_ASTEROIDS];
	int numOfAsteroids = 2;
	int numOfSmallAsteroids = 3;
	sf::Sprite backRoundSprite;
	sf::Texture backRoundTexture;


	int slowAsteroidPowerCounter = 1;
public:
	
	GameState currentState;
	Game();
	~Game();
	void run();
	bool press;
	int helpTimer = 20;
	int licenseTimer = 60;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	sf::Font m_ArialBlackfont; // font used by message
	void setupFontAndText();
	void setupSprite();
	void setUpBullets();
	void bulletMove();
	void mouseClicks(sf::Event t_event, sf::RenderWindow &t_window);
	bool asteroidShot = false;
	sf::RenderWindow m_window; // main SFML window
	void bulletHitLargeAsteroid(int t_asteroidArrayPosition);
	void bulletHitMediumAsteroid(int t_asteroidArrayPosition);
	void bulletHitSmallAsteroid(int t_asteroidArrayPosition);
	bool m_exitGame; // control exiting game
	void changeState();
	void timer();
	void scoreTracker();
	void collision();
	void slowAsteroids();
	void normalAsteroids();
};
