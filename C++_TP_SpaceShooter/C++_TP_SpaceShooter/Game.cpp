#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(const std::string& title) :	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), title) {
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
	}
}

void Game::update() {
	float timeBetween = clock.getElapsedTime().asSeconds();
	clock.restart();

	background.updateTexture(timeBetween);
}

void Game::render() {
	window.clear();
	background.drawBackGround(window);
	window.display();
}