#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(const std::string& title) : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), title), spaceship(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 8 * 6) {
	background.setTexture();
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
		spaceship.display(event);
	}
}

void Game::update() {
	float timeBetween = clock.getElapsedTime().asSeconds();
	clock.restart();

	background.update(timeBetween);
}

void Game::render() {
	window.clear();
	background.draw(window);
	spaceship.draw(window);
	window.display();
}