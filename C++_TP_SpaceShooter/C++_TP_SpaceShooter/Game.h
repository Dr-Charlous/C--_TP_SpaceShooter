#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "Spaceship.h"

class Game
{
public:
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 600;

	Game(const std::string& title);

	void run();
	void processEvents();
	void update();
	void render();

protected:
	sf::Clock clock;
	sf::RenderWindow window;
	BackGround background;
	Spaceship spaceship;
};

