#include "EnnemySpawner.h"
#include "GameObject.h"
#include "EnnemyShip.h"

void EnnemySpawner::createEnnemy(std::vector<GameObject*> &objectsInScene)
{
	EnnemyShip* ennemy = new EnnemyShip("EnnemyShip", 0, 0, "Assets/Shooter/spaceship.png");
	objectsInScene.push_back(ennemy);
}

void EnnemySpawner::deleteEnnemy(std::vector<GameObject*> &objectsInScene)
{
	for (int i = 0; i < objectsInScene.size(); i++) {
		if (objectsInScene[i]->getNameClass() == "EnnemyShip") {
			objectsInScene.erase(objectsInScene.begin() + i);
			break;
		}
	}
}
