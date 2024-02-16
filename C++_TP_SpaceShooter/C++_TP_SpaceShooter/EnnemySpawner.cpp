#include "EnnemySpawner.h"
#include "GameObject.h"
#include "EnnemyShip.h"
#include <SFML/Graphics.hpp>

EnnemySpawner::EnnemySpawner() :
	timeBetweenSpawn(2)
{
}

void EnnemySpawner::createEnnemy(std::vector<GameObject*> &objectsInScene)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenSpawn)
	{
		clock.restart();
		EnnemyShip* ennemy = new EnnemyShip("EnnemyShip", 0, 0, "Assets/Shooter/spaceship.png");
		ennemy->getSprite().setRotation(180);
		ennemy->setX(ennemy->getX() + ennemy->textureSpaceShip.getSize().x);
		objectsInScene.push_back(ennemy);
	}
}

//void EnnemySpawner::deleteEnnemy(std::vector<GameObject*> &objectsInScene)
//{
//	for (int i = 0; i < objectsInScene.size(); i++) {
//		if (objectsInScene[i]->getNameClass() == "EnnemyShip") {
//			objectsInScene.erase(objectsInScene.begin() + i);
//			break;
//		}
//	}
//}
