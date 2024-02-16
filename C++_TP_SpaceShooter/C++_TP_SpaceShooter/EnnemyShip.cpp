#include "EnnemyShip.h"
#include "Game.h"
#include <iostream>

EnnemyShip::EnnemyShip(std::string _nameClass, float _x, float _y, std::string _spriteLocation) :
	GameObject(_nameClass, _x, _y, _spriteLocation),
	timeBetweenFire(2)
{
}

void EnnemyShip::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*> objectsToDelete)
{
	if (y - textureSpaceShip.getSize().y <= Game::WINDOW_HEIGHT) {
		backward(_time);
		fire();
	}
	else {
		objectsToDelete.push_back(this);
	}
}

void EnnemyShip::fire()
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenFire)
	{
		clock.restart();
		std::cout << "Fire" << std::endl;
	}
}