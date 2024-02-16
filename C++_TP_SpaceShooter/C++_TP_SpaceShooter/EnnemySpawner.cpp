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

void EnnemySpawner::createEnnemy(std::vector<GameObject*> &objectsInScene)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenSpawn)
	{
		clock.restart();
		EnnemyShip* ennemy = new EnnemyShip("EnnemyShip", 0, 0, "Assets/Shooter/spaceship.png");
		ennemy->getSprite().setRotation(180);

		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, Game::WINDOW_WIDTH - ennemy->textureSpaceShip.getSize().x); // define the range

		ennemy->setX(ennemy->getX() + ennemy->textureSpaceShip.getSize().x + distr(gen));

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
