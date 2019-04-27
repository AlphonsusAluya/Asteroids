
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
						for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
						{
							MyVector3 newLocation = { asteroidsL[2].location.x + LARGE_ASTEROID_IMAGE_SIZE / 2, asteroidsL[2].location.y + LARGE_ASTEROID_IMAGE_SIZE / 2, 0 };
							smallAsteroids[i].positioning(newLocation, asteroidsL[2].velocity);
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
void Game::update(sf::Time t_deltaTime)
{
	if (currentState == GameState::GamePlay)
	{	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			int x = player.velocity.x;
			int y = player.velocity.y;
			bullet.setBulletVelocity(x, y);			// the bullets firing
			bullet.fire();
		}
		
		if (paused == false)
		{
			collision();
			for (int i = 0; i < numOfAsteroids; i++)
			{
				asteroidsL[i].update();
				mediumAsteroids[i].update();
			}
			player.update();
			for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)		//if the game isnt paused the game will continue as normal
			{
				smallAsteroids[i].update();
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
	for (int i = 0; i < numOfAsteroids; i++)
	{
		if (asteroidsL[i].sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
		{
			player.decreaseHealth(1); // large asteroid collision
		}

		if (mediumAsteroids[i].sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
		{
			player.decreaseHealth(2); // med asteroid collison
		}

		if (smallAsteroids[i].sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
		{
			player.decreaseHealth(3); // med asteroid collison
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
		sound.gamePlaySound();
		m_window.draw(backRoundSprite);
		for (int i = 0; i < numOfAsteroids; i++)
		{
			asteroidsL[i].draw(m_window);
			mediumAsteroids[i].draw(m_window);		//draws the screen and anything necessary for the game play
		}
		m_window.draw(healthMessage);
		player.draw(m_window);
		bullet.draw(m_window);
		for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
		{
			smallAsteroids[i].draw(m_window);
		}

	}

	if (currentState == GameState::PauseMenu)
	{
		
		m_window.draw(backRoundSprite);
		for (int i = 0; i < numOfAsteroids; i++)
		{
			asteroidsL[i].draw(m_window);
			mediumAsteroids[i].draw(m_window);			//draws the screen and anything necessary for the pause menu
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
				std::cout << "gameplay";
				currentState = GameState::GamePlay;
			}

			if (position.y >= 220 && position.y <= 320) // help menu
			{
				std::cout << "help";
				currentState = GameState::HelpScreen;
			}

			if (position.y >= 321) // help menu
			{
				std::cout << "upgrade";
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
					std::cout << "gameplay mup";
					paused = false;
					currentState = GameState::GamePlay;
				}

				if (position.y >= 220 && position.y <= 320) // help menu
				{
					std::cout << "help";
					currentState = GameState::HelpScreen;
				}

				if (position.y >= 321) // help menu
				{
					std::cout << "upgrade";
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
