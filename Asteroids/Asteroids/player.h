#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{

	int lives;
	int direction;
	int speed = 3;
	int score;

	bool m_alive = true;

	

public:

	sf::Texture playerTexture;



	sf::Sprite body;
	sf::Sprite getBody();


	    Player();
	    
		void loadImage();
		void moveLeft();
		void moveRight();
		void moveDown();
		void moveUp();
		void dies();

};
