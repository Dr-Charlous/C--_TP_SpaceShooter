#include "EnnemyShip.h"
#include "Game.h"
#include <iostream>
#include "Projectile.h"

EnnemyShip::EnnemyShip(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& _objectsInScene, std::vector<GameObject*>& objectsToAdd) :
	GameObject(_nameClass, _x, _y, _spriteLocation, objectsInScene, objectsToAdd),
	timeBetweenFire(2 - (std::rand() % 2))
{
}

void EnnemyShip::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsToDelete)
{
	if (y - textureSpaceShip.getSize().y <= Game::WINDOW_HEIGHT) {
		backward(_time);
		fire(objectsInScene, objectsToAdd);
	}
	else {
		objectsToDelete.push_back(this);
		collision(objectsInScene, objectsToDelete);
	}
}

void EnnemyShip::fire(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenFire)
	{
		clock.restart();
		std::cout << "Fire" << std::endl;
		Projectile* projectile = new Projectile("Projectile", x + textureSpaceShip.getSize().x / 2, y, "Assets/Shooter/laser2.png", objectsInScene, objectsToAdd);
		projectile->setSpeed(-200);
		projectile->setY(y + projectile->textureSpaceShip.getSize().y * 2);
		objectsToAdd.push_back(projectile);
	}
}