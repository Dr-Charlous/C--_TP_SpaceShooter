#include "EnnemyShip.h"
#include "Game.h"
#include <iostream>
#include "Projectile.h"

EnnemyShip::EnnemyShip(std::string _nameClass, float _x, float _y, int _hp, std::string _spriteLocation, std::vector<GameObject*>& _objectsInScene, std::vector<GameObject*>& objectsToAdd) :
	GameObject(_nameClass, _x, _y, _hp, _spriteLocation, objectsInScene, objectsToAdd),
	timeBetweenFire(2 - (std::rand() % 2)),
	scoreGiven(120)
{
}

void EnnemyShip::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	if (y - textureSpaceShip.getSize().y <= Game::WINDOW_HEIGHT) {
		collision(objectsInScene, objectsToDelete);
		backward(_time);
		fire(objectsInScene, objectsToAdd);
	}
	else {
		objectsToDelete.push_back(this);
	}
}

void EnnemyShip::fire(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenFire)
	{
		clock.restart();
		Projectile* projectile = new Projectile("Projectile", x + textureSpaceShip.getSize().x / 2, y, 1, "Assets/Shooter/laser2.png", objectsInScene, objectsToAdd);
		projectile->setSpeed(-300);
		projectile->setY(y + projectile->textureSpaceShip.getSize().y * 2);
		objectsToAdd.push_back(projectile);
	}
}

void EnnemyShip::collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	/*if (objectsInScene.size() > 0) {
		for (size_t i = 0; i < objectsInScene.size(); i++)
		{
			if (objectsInScene[i]->getNameClass() != nameClass) {
				float x1 = x;
				float x2 = x + textureSpaceShip.getSize().x;
				float x3 = objectsInScene[i]->getX();
				float x4 = objectsInScene[i]->getX() + objectsInScene[i]->textureSpaceShip.getSize().x;
				float y1 = y;
				float y2 = y + textureSpaceShip.getSize().y;
				float y3 = objectsInScene[i]->getY();
				float y4 = objectsInScene[i]->getY() + objectsInScene[i]->textureSpaceShip.getSize().y;

				if (x3 <= x2 && x3 >= x1 && x4 >= x1 && x4 >= x2 && y3 <= y2 && y3 >= y1 && y4 >= y1 && y4 >= y2)
				{
					objectsToDelete.push_back(objectsInScene[0]);
				}
			}
		}
	}*/
}