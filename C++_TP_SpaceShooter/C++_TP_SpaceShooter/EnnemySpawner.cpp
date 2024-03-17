#include "EnnemySpawner.h"
#include "GameObject.h"
#include "EnnemyShip.h"
#include <SFML/Graphics.hpp>
#include <random>
#include "Game.h"

EnnemySpawner::EnnemySpawner() :
	timeBetweenSpawn(2)
{
}

void EnnemySpawner::createEnnemy(std::vector<GameObject*> & objectsInScene, std::vector<GameObject*>& objectsToAdd)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenSpawn)
	{
		clock.restart();
		EnnemyShip* ennemy = new EnnemyShip("EnnemyShip", 0, 0, 1, "Assets/Shooter/enemy.png", objectsInScene, objectsToAdd);

		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, Game::WINDOW_WIDTH - ennemy->textureSpaceShip.getSize().x); // define the range

		ennemy->setX(ennemy->getX() + distr(gen));

		objectsToAdd.push_back(ennemy);
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
