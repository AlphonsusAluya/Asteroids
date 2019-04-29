
#include "game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Asteroids" },
	m_exitGame{ false } //when true game will exit
{
	Game::currentState = GameState::LicenseScreen;
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	/*for (int i = 0; i < NUMOFBULLETS; i++)
	{
		bullet[i].setupBullets();
	}
	*/
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		
		
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			   
			if (currentState == GameState::SplashScreen)
			{
				if (sf::Keyboard::isKeyPressed)
				{
					currentState = GameState::MainMenuScreen; // menu screen 
				}
			}

			if (currentState == GameState::UpgradeScreen)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					currentState = GameState::MainMenuScreen; // when in the upgrade screen it reurns back to the menu screen
				}
			}

			if (currentState == GameState::UpgradeHelp)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				{
					currentState = GameState::HelpScreen; // goes to the help screen from the upgrade help
				}
			}

			if (currentState == GameState::PickUpHelp)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				{
					currentState = GameState::HelpScreen; // goes to the help screen from the pickup help if requested
				}
			}
				if (currentState == GameState::GamePlay)
				{
					player.rotate(event);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) // going to be collision between bullet and asteroid
					{
						bulletHitLargeAsteroid(1);
					}
					if (paused == false)
					{
						if (event.key.code == sf::Keyboard::Space)
						{
							setUpBullets();
						}
					}
				}
		}
		mouseClicks(event, m_window);
	}
}
/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
/// 
void Game::bulletHitLargeAsteroid(int t_asteroidArrayPosition)
{
	player.addScore(5);
	asteroidsL[t_asteroidArrayPosition].wasShot = true;
	MyVector3 newLocation = { asteroidsL[t_asteroidArrayPosition].location.x + LARGE_ASTEROID_IMAGE_SIZE / 2, asteroidsL[t_asteroidArrayPosition].location.y + LARGE_ASTEROID_IMAGE_SIZE / 2, 0 };
	for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
	{
		smallAsteroids[i].positioning(newLocation, asteroidsL[t_asteroidArrayPosition].velocity);
	}
}

void Game::bulletHitMediumAsteroid(int t_asteroidArrayPosition)
{
	player.addScore(3);
	mediumAsteroids[t_asteroidArrayPosition].wasShot = true;
	MyVector3 newLocation = { mediumAsteroids[t_asteroidArrayPosition].location.x + LARGE_ASTEROID_IMAGE_SIZE / 2, mediumAsteroids[t_asteroidArrayPosition].location.y + LARGE_ASTEROID_IMAGE_SIZE / 2, 0 };
	for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
	{
		smallAsteroids[i].positioning(newLocation, mediumAsteroids[t_asteroidArrayPosition].velocity);
	}
}

void Game::bulletHitSmallAsteroid(int t_asteroidArrayPosition)
{
	player.addScore(1);
	mediumAsteroids[t_asteroidArrayPosition].wasShot = true;
}
void Game::update(sf::Time t_deltaTime)
{
	if (currentState == GameState::GamePlay)
	{	
		if (paused == false)
		{
			collision();
			for (int i = 0; i < numOfAsteroids; i++)
			{
				if (asteroidsL[i].wasShot == false)
				{
					asteroidsL[i].update();
				}
				
				if (mediumAsteroids[i].wasShot == false)
				{
					mediumAsteroids[i].update();
				}
				for (int i = 0; i < NUMOFBULLETS; i++)
				{
					bullet[i].fire();
				}

				
			}
			player.update();
			for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)		//if the game isnt paused the game will continue as normal
			{
				if (smallAsteroids[i].wasShot == false)
				{
					smallAsteroids[i].update();
				}
				
			}
		}
	}
	
	changeState();
	timer();
	if (m_exitGame)
	{
		m_window.close();
	}
}


void Game::collision()
{
	MyVector3 distanceLarge;
	float length;

	MyVector3 distanceMedium;
	float lengthMedium;

	MyVector3 distanceSmall;
	float lengthSmall;

	int LARGE_IMAGE_LENTH = 93;
	int MEDIUM_IMAGE_LENTH = 58;
	int SMALL_IMAGE_LENTH = 29;
	for (int i = 0; i < numOfAsteroids; i++)
	{
		MyVector3 LargeLocation = { asteroidsL[i].location.x + 48, asteroidsL[i].location.y + 48, 0 };
		MyVector3 mediumLocation = { mediumAsteroids[i].location.x + 32, mediumAsteroids[i].location.y + 32, 0 };

		distanceLarge = LargeLocation - player.location;
		length = distanceLarge.length();

		distanceMedium = mediumLocation - player.location;
		lengthMedium = distanceMedium.length();

		if (asteroidsL[i].wasShot == false)
		{
			if (length <= LARGE_IMAGE_LENTH)
			{
				player.decreaseHealth(1); // large asteroid collision
				
			}
		}

		if (mediumAsteroids[i].wasShot == false)
		{

			if (lengthMedium <= MEDIUM_IMAGE_LENTH)
			{
				player.decreaseHealth(2); // med asteroid collison
				
			}
		}
	}

	for (int i = 0; i <= MAX_SMALL_ASTEROIDS; i++)
	{
		if (smallAsteroids[i].wasShot == false)
		{
			MyVector3 smallLocation = { smallAsteroids[i].location.x + 16, smallAsteroids[i].location.y + 16, 0 };
			distanceSmall = smallLocation - player.location;
			lengthSmall = distanceSmall.length();

			if (lengthSmall <= SMALL_IMAGE_LENTH)
			{
				player.decreaseHealth(3); // med asteroid collison
				
			}
		}
	}
		
		
	
}
/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	if (currentState == GameState::LicenseScreen)
	{
		license.draw(m_window);			//draws the screen
	}
	
	if (currentState == GameState::SplashScreen)
	{
		splash.draw(m_window);		//draws the screen
	}

	if (currentState == GameState::MainMenuScreen)
	{
		menu.draw(m_window);		//draws the screen
		sound.menuSound(); // makes menu noise
	}

	if (currentState == GameState::HelpScreen)
	{
		help.draw(m_window);		//draws the screen
	}
	if (currentState == GameState::ControlHelp)
	{
		controlHelp.draw(m_window);		//draws the screen
	}

	if (currentState == GameState::UpgradeScreen)
	{
		upgrade.draw(m_window);		//draws the screen
	}

	if (currentState == GameState::UpgradeHelp)
	{
		upgradeHelp.draw(m_window);		//draws the screen
	}

	if (currentState == GameState::PickUpHelp)
	{
		pickUp.draw(m_window);		//draws the screen
	}

	if (currentState == GameState::GamePlay)
	{
		healthMessage.setString("Health:" + std::to_string(player.getHealth()));
		scoreMessage.setString("Score:" + std::to_string(player.getScore()));
		sound.gamePlaySound();
		
		for (int i = 0; i < NUMOFBULLETS; i++)
		{
			//bullet[i].draw(m_window);
			m_window.draw(bullet[i].getBody());
		}m_window.draw(backRoundSprite);
		for (int i = 0; i < numOfAsteroids; i++)
		{
			if (asteroidsL[i].wasShot == false)
			{
				asteroidsL[i].draw(m_window);
			}

			if (mediumAsteroids[i].wasShot == false)
			{
				mediumAsteroids[i].draw(m_window);
			}
		}
		m_window.draw(healthMessage);
		m_window.draw(scoreMessage);
		player.draw(m_window);
		
		
		for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
		{
			if (smallAsteroids[i].wasShot == false)
			{
				smallAsteroids[i].draw(m_window);
			}
		}

	}

	if (currentState == GameState::PauseMenu)
	{
		
		m_window.draw(backRoundSprite);
		for (int i = 0; i < numOfAsteroids; i++)
		{
			if (asteroidsL[i].wasShot == false)
			{
				asteroidsL[i].draw(m_window);
			}

			if (mediumAsteroids[i].wasShot == false)
			{
				mediumAsteroids[i].draw(m_window);
			}
		}

		player.draw(m_window);

		for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
		{
			smallAsteroids[i].draw(m_window);
		}
		pause.draw(m_window);
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText() // sets up fonts and texts
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	healthMessage.setFont(m_ArialBlackfont);
	
	healthMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	healthMessage.setPosition(5.0f, 30.0f);
	healthMessage.setCharacterSize(25);
	healthMessage.setOutlineColor(sf::Color::Red);
	healthMessage.setFillColor(sf::Color::Black);
	healthMessage.setOutlineThickness(3.0f);

	scoreMessage.setFont(m_ArialBlackfont);

	scoreMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	scoreMessage.setPosition(5.0f, 70.0f);
	scoreMessage.setCharacterSize(25);
	scoreMessage.setOutlineColor(sf::Color::Red);
	scoreMessage.setFillColor(sf::Color::Black);
	scoreMessage.setOutlineThickness(3.0f);

	splash.init(m_ArialBlackfont);
	license.init(m_ArialBlackfont);
	menu.init(m_ArialBlackfont);
	help.init(m_ArialBlackfont);
	pause.init(m_ArialBlackfont);
	upgrade.init(m_ArialBlackfont);
	upgradeHelp.init(m_ArialBlackfont);
	pickUp.init(m_ArialBlackfont);

	controlHelp.init(m_ArialBlackfont);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!backRoundTexture.loadFromFile("ASSETS/IMAGES/gameplay.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading gmaeplay backround" << std::endl;
	}


	backRoundSprite.setTexture(backRoundTexture); // sets sprite
}

void Game::setUpBullets()
{
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		if (bullet[i + 1].readyToFire == true && bullet[i].readyToFire == true)
		{
			if (bullet[i].bullets.getPosition() == bullet[i].Onscreen && bullet[i + 1].bullets.getPosition() == bullet[i + 1].Onscreen)
			{
				bullet[i].bullets.setPosition(player.getBody().getPosition() + sf::Vector2f(25, 25));
				bullet[i +1].bullets.setPosition(player.getBody().getPosition() + sf::Vector2f(-25, -25));

				bullet[i].bulletVelocity = player.lookDirection;
				bullet[i].bulletVelocity.x = bullet[i].bulletVelocity.x * 8;
				bullet[i].bulletVelocity.y = bullet[i].bulletVelocity.y * 8;
				bullet[i].readyToFire = false;
				bullet[i].waitCounter = 10;

				bullet[i + 1].bulletVelocity = player.lookDirection;
				bullet[i + 1].bulletVelocity.x = bullet[i].bulletVelocity.x * 8;
				bullet[i + 1].bulletVelocity.y = bullet[i].bulletVelocity.y * 8;
				bullet[i + 1].readyToFire = false;
				bullet[i + 1].waitCounter = 10;

				i = i + 2;

				sound.laserSound();
				break;
			}
			
		}
		else
		{
			bullet[i].waitCounter--;
			bullet[i + 1].waitCounter--;

			if (bullet[i].waitCounter <= 0)
			{
				bullet[i].readyToFire = true;
			}

			if (bullet[i + 1].waitCounter <= 0)
			{
				bullet[i + 1].readyToFire = true;
			}
		}
	}
}

//void Game::ifNotReady()
//{
//	for (int i = 0; i < NUMOFBULLETS; i++)
//	{
//		bullet[i].waitToFire--;
//		bullet[i + 1].waitToFire--;
//
//		if (bullet[i].waitToFire <= 0)
//		{
//			bullet[i].readyToFire = true;
//		}
//
//		if (bullet[i + 1].waitToFire <= 0)
//		{
//			bullet[i + 1].readyToFire = true;
//		}
//	}
//}



void Game::mouseClicks(sf::Event t_event, sf::RenderWindow &t_window)
{
	if (currentState == GameState::MainMenuScreen)
	{
		helpTimer = 30;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i position = sf::Mouse::getPosition(t_window);

			if (position.y <= 220) // first button / start game
			{
				currentState = GameState::GamePlay;
				paused = false;
			}

			if (position.y >= 220 && position.y <= 320) // help menu
			{
				currentState = GameState::HelpScreen;
			}

			if (position.y >= 321) // help menu
			{
				currentState = GameState::UpgradeScreen;
			}
		}

		
	}



	if (currentState == GameState::PauseMenu)
	{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(t_window);
				int output = position.y;
				std::cout << output;
				if (position.y <= 220) // first button / start game
				{
					paused = false;
					currentState = GameState::GamePlay;
				}

				if (position.y >= 220 && position.y <= 320) // help menu
				{
					currentState = GameState::MainMenuScreen;
				}

				if (position.y >= 321) // help menu
				{
					currentState = GameState::UpgradeScreen;
				}
			}		
	}
	if (currentState == GameState::GamePlay)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i position = sf::Mouse::getPosition(t_window);

			if (position.y <= 40 && position.x <= 40) // first button / start game
			{
				currentState = GameState::PauseMenu;
				paused = true;
			}
		}
	}

	if (currentState == GameState::ControlHelp)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))  // goes to help screen if needed
		{
			currentState = GameState::HelpScreen;
		}
	}
	if (currentState == GameState::HelpScreen)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // goes to the main menu
		{
			currentState = GameState::MainMenuScreen;
		}
		
		if (helpTimer <= 3)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(t_window);

				if (position.y <= 220) // first button / start game
				{
					currentState = GameState::ControlHelp;
				}

				if (position.y >= 220 && position.y <= 320) // help menu
				{
					currentState = GameState::PickUpHelp;
				}

				if (position.y >= 321) // help menu
				{
					currentState = GameState::UpgradeHelp;
				}
			}
		}
	}

}
void Game::timer()
{
	licenseTimer--;
	helpTimer--;

}
void Game::changeState()
{
	if (currentState == GameState::LicenseScreen)
	{
		if (licenseTimer <= 0)
		{	
			currentState = GameState::SplashScreen; // timer to change screen
		}
	}
}
