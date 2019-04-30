
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
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) // going to be collision between bullet and asteroid // testing
					{
						bulletHitLargeAsteroid(1);
					}
					if (paused == false)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						{
							press = true;
							setUpBullets(); // fires the bullets
							
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
	for (int i = 0; i < numOfSmallAsteroids; i++)
	{
		smallAsteroids[i].positioning(newLocation, asteroidsL[t_asteroidArrayPosition].velocity);
	}
	asteroidsL[t_asteroidArrayPosition].positioning();
}

void Game::bulletHitMediumAsteroid(int t_asteroidArrayPosition)
{
	player.addScore(5);
	mediumAsteroids[t_asteroidArrayPosition].wasShot = true;
	MyVector3 newLocation = { mediumAsteroids[t_asteroidArrayPosition].location.x + LARGE_ASTEROID_IMAGE_SIZE / 2, mediumAsteroids[t_asteroidArrayPosition].location.y + LARGE_ASTEROID_IMAGE_SIZE / 2, 0 };
	for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
	{
		smallAsteroids[i].positioning(newLocation, mediumAsteroids[t_asteroidArrayPosition].velocity);
	}
	mediumAsteroids[t_asteroidArrayPosition].positioning();
}

void Game::bulletHitSmallAsteroid(int t_asteroidArrayPosition)
{
	player.addScore(5);
	mediumAsteroids[t_asteroidArrayPosition].wasShot = true;
}
void Game::update(sf::Time t_deltaTime)
{
	if (currentState == GameState::GamePlay)
	{	
		if (paused == false)
		{
			for (int i = 0; i < NUMOFBULLETS; i++)
			{

				bullet[i].fire(); // checks the bullets 
				
			}
			
			bulletMove();
		
				
				
		} // end for

			collision();
			for (int i = 0; i < numOfAsteroids; i++)
			{

				asteroidsL[i].update();
				mediumAsteroids[i].update();
				

		/*		for (int i = 0; i < NUMOFBULLETS; i++)
				{
					bullet[i].fire();
				}*/
				
			} // end for

			for (int i = 0; i < MAX_PICK_UPS; i++)
			{
				pickUps[i].update();
			}
			
			if(anotherRound == true)
			{
				if (numOfAsteroids < MAX_ASTEROIDS)
				{
					numOfAsteroids++;

					for (int i = 0; i < MAX_PICK_UPS; i++)		// if the game isnt paused the game will continue as normal
					{
						pickUps[i].reset();
					}
					anotherRound = false;
					player.addScore(5);
				}
				else
					gameOver = true;	
				
			}
			player.update();
			scoreTracker();
			normalAsteroids();
			for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)		//if the game isnt paused the game will continue as normal
			{
				if (smallAsteroids[i].wasShot == false)
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
void Game::slowAsteroids()
{
	if (asteroidSlow == false)
	{
		for (int i = 0; i < numOfAsteroids; i++)
		{
			asteroidsL[i].velocity = asteroidsL[i].velocity * 0.5;
			mediumAsteroids[i].velocity = mediumAsteroids[i].velocity * 0.5;
		}

		for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)		//if the game isnt paused the game will continue as normal
		{
			smallAsteroids[i].velocity = smallAsteroids[i].velocity * 0.5;
		}
		asteroidSlow = true;
	}
		
}

void Game::normalAsteroids() // sets back to normal pace after power up
{
	if (slowAsteroidPowerCounter < 0)
	{
		if (asteroidSlow == true)
		{
			for (int i = 0; i < numOfAsteroids; i++)
			{
				asteroidsL[i].velocity = asteroidsL[i].velocity * 2;
				mediumAsteroids[i].velocity = mediumAsteroids[i].velocity * 2;
			}

			for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)		//if the game isnt paused the game will continue as normal
			{
				smallAsteroids[i].velocity = smallAsteroids[i].velocity * 2;
			}
			asteroidSlow = false;
		}
	}


}

void Game::scoreTracker()
{
	if (player.getScore() == 50)
	{
		anotherRound = true;
	}

	if (player.getScore() == 100)
	{
		anotherRound = true;
	}

	if (player.getScore() == 150)
	{
		anotherRound = true;
	}

	if (player.getScore() == 200)
	{
		anotherRound = true;
	}

	if (player.getScore() == 250)
	{
		anotherRound = true;
	}

	if (player.getScore() == 300) // max asteroids
	{
		anotherRound = true;
	}

}

void Game::collision()
{

//////////////////////////////////////////////// <summary>
	/// collisions with Asteroids
////////////////////////////////////////////////<summary>

	MyVector3 distanceLarge;
	float length;

	MyVector3 distanceMedium;
	float lengthMedium;

	MyVector3 distanceSmall;
	float lengthSmall;

	
	int LARGE_IMAGE_LENTH = 96;
	int MEDIUM_IMAGE_LENTH = 64;
	int SMALL_IMAGE_LENTH = 32;

	float largeSize = (LARGE_IMAGE_LENTH / 2 + player.REAL_SIZE / 2);
	float mediumSize = (MEDIUM_IMAGE_LENTH / 2 + player.REAL_SIZE / 2);
	float smallSize = (SMALL_IMAGE_LENTH / 2 + player.REAL_SIZE / 2);

	float smallBulletSize = (LARGE_IMAGE_LENTH / 2 + 8);

	for (int i = 0; i < numOfAsteroids; i++)
	{


		MyVector3 LargeLocation = { asteroidsL[i].location.x + 48, asteroidsL[i].location.y + 48, 0 }; // finds centre of large asteroid image
		MyVector3 mediumLocation = { mediumAsteroids[i].location.x + 32, mediumAsteroids[i].location.y + 32, 0 };  // finds centre of medium asteroid image

		distanceLarge = LargeLocation - player.location;
		length = distanceLarge.length();

		distanceMedium = mediumLocation - player.location;
		lengthMedium = distanceMedium.length();

	
		if (asteroidsL[i].wasShot == false)
		{
			if (length <= largeSize)
			{
				player.decreaseHealth(1); // large asteroid collision
				player.changeColourToRed(); // change colour to transparent when being hit with asteroid
			}
			else
			{
				player.changeColourToNormal(); // its normal colour
			}
			
		}

		if (mediumAsteroids[i].wasShot == false)
		{
			if (lengthMedium <= mediumSize)
			{
				player.decreaseHealth(2); // med asteroid collison
				player.changeColourToRed();
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

			if (lengthSmall <= smallSize)
			{
				player.changeColourToRed();
				player.decreaseHealth(3); // med asteroid collison	
			}
		}
	}

	for (int i = 0; i <= MAX_PICK_UPS; i++)
	{
		if (pickUps[i].pickedUp == false)
		{
			MyVector3 smallLocation = { pickUps[i].location.x + 16, pickUps[i].location.y + 16, 0 };
			distanceSmall = smallLocation - player.location;
			lengthSmall = distanceSmall.length();

			if (lengthSmall <= smallSize)
			{
				if (pickUps[i].getWhichPowerUp() == 1)
				{
					slowAsteroids();
					slowAsteroidPowerCounter = 300;
					pickUps[i].pickedUp = true;
				}

				if (pickUps[i].getWhichPowerUp() == 2)
				{
					//player.changeColourToRed();
					player.increaseHealth(10);
					pickUps[i].pickedUp = true;
				}

			}
		}

		for (int i = 0; i < numOfAsteroids; i++)
		{
			for (int j = 0; j <= NUMOFBULLETS; j++)
			{
				MyVector3 LargeLocation = { asteroidsL[i].location.x + 48, asteroidsL[i].location.y + 48, 0 }; // finds centre of large asteroid image
				MyVector3 smallLocation = { bullet[j].getBody().getPosition().x + 8, bullet[j].getBody().getPosition().y + 8, 0 };
				MyVector3 mediumLocation = { mediumAsteroids[i].location.x + 32, mediumAsteroids[i].location.y + 32, 0 };  // finds centre of medium asteroid image
				distanceSmall = LargeLocation - smallLocation; // distance between large asteroid and bullet
				lengthSmall = distanceSmall.length();

				distanceMedium = mediumLocation - smallLocation;
				lengthMedium = distanceMedium.length();

				if (lengthSmall <= smallBulletSize) // colision with large asteroid
				{
					bulletHitLargeAsteroid(i);
				}

				if (lengthMedium <= smallBulletSize) // colision with large asteroid
				{
					bulletHitMediumAsteroid(i);
				}

			}
		}
		
	}

///////////////////////////////// <summary>
/// collisions with bullet
//////////////////////////////////// </summary>




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

		m_window.draw(healthMessage);
		m_window.draw(scoreMessage);
		player.draw(m_window);

		for (int i = 0; i < NUMOFBULLETS; i++)
		{
			bullet[i].draw(m_window);		//supposed to draw bullets
		}

		

		
		for (int i = 0; i < MAX_SMALL_ASTEROIDS; i++)
		{
			if (smallAsteroids[i].wasShot == false)
			{
				smallAsteroids[i].draw(m_window);
			}
		}
		m_window.draw(healthMessage);
		m_window.draw(scoreMessage);
		player.draw(m_window);

		for (int i = 0; i < MAX_PICK_UPS; i++)
		{
			if (pickUps[i].pickedUp == false)
			{
				pickUps[i].draw(m_window);
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
		if (bullet[i + 1].readyToFire == true && bullet[i].readyToFire == true) // checks if its ready to fire
		{
			if (bullet[i].bullets.getPosition() == bullet[i].Onscreen && bullet[i + 1].bullets.getPosition() == bullet[i + 1].Onscreen) // checks if its on screen
			{
				bullet[i].setPos(player.location + sf::Vector2f(25, 25));
				bullet[i +1].setPos(player.location + sf::Vector2f(-25, -25)); // sets two bullet positions

				bullet[i].bulletVelocity = player.getDirection(); // sets the velocity to the player look direction
				bullet[i].bulletVelocity.x = bullet[i].bulletVelocity.x * 8; // multiplies it so it moves
				bullet[i].bulletVelocity.y = bullet[i].bulletVelocity.y * 8;
				bullet[i].readyToFire = false; // changes the bool
				bullet[i].waitCounter = 10; // set the wait counter

				bullet[i + 1].bulletVelocity = player.getDirection(); // sets the velocity to the player look direction
				bullet[i + 1].bulletVelocity.x = bullet[i].bulletVelocity.x * 2; // multiplies it so it moves
				bullet[i + 1].bulletVelocity.y = bullet[i].bulletVelocity.y * 2;
				bullet[i + 1].readyToFire = false; // changes the bool
				bullet[i + 1].waitCounter = 10; // set the wait counter

				

				sound.laserSound();
				break;
			}
			
		}
		else
		{
			if (bullet[i].bullets.getPosition().x > 800 || bullet[i].bullets.getPosition().y > 600 || bullet[i].bullets.getPosition().x < 0 || bullet[i].bullets.getPosition().y < 0 ||
				bullet[i + 1].bullets.getPosition().x > 800 || bullet[i + 1].bullets.getPosition().y > 600 || bullet[i + 1].bullets.getPosition().x < 0 || bullet[i + 1].bullets.getPosition().y < 0)
			{
				bullet[i].readyToFire = true;
				bullet[i + 1].readyToFire = true;
				press = false;
			}
			
		}
	}
}

void Game::bulletMove()
{
	for (int i = 0; i < NUMOFBULLETS; i++)
	{
		if (press == true)
		{
			bullet[i].bullets.move(bullet[i].bulletVelocity);
		}

	}
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

	if (asteroidSlow == true)
	{
		slowAsteroidPowerCounter--;
	}
	
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
