#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "Spaceship.h"
#include "EnnemySpawner.h"
#include "EnnemyShip.h"

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

	std::vector<GameObject*> objectsInScene;
	std::vector<GameObject*> objectsToDelete;
	std::vector<GameObject*> objectsToAdd;
	//bool contains(const std::vector<GameObject*>& vec, const GameObject* coord);

protected:
	sf::Clock clock;
	sf::RenderWindow window;
	BackGround background;
	EnnemySpawner ennemySpawner;
	Spaceship spaceship;
};

