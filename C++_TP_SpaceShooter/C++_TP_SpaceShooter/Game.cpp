#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(const std::string& title) :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), title),
	spaceship("SpaceShip", WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 8 * 6, "Assets/Shooter/spaceship.png")
{
	background.setTexture();
	objectsInScene.push_back(&spaceship);

	ennemySpawner.createEnnemy(objectsInScene);
}

void Game::run() {
	while (window.isOpen()) {
		this->processEvents();
		this->update();
		this->render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

	}
	float timeBetween = clock.getElapsedTime().asSeconds();

	for (int i = 0; i < objectsInScene.size(); i++) {
		if (contains(objectsInScene, objectsInScene[i]))
			objectsInScene[i]->inputs(window, event, timeBetween);
		else
			objectsInScene.erase(objectsInScene.begin() + i);
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//	ennemySpawner.deleteEnnemy(objectsInScene);
}

void Game::update() {
	float timeBetween = clock.getElapsedTime().asSeconds();
	clock.restart();

	for (int i = 0; i < objectsInScene.size(); i++) {
		objectsInScene[i]->update(timeBetween);
	}

	background.update(timeBetween);
}

void Game::render() {
	window.clear();
	background.draw(window);

	for (int i = 0; i < objectsInScene.size(); i++) {
		objectsInScene[i]->draw(window);
	}

	window.display();
}

bool Game::contains(const std::vector<GameObject*>& vec, const GameObject* coord)
{
	return std::find(vec.begin(), vec.end(), coord) != vec.end();
}
