#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

class EnnemySpawner
{
public:
	EnnemySpawner();
	void createEnnemy(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd);
	//void deleteEnnemy(std::vector<GameObject*>& objectsInScene);

protected :
	sf::Clock clock;
	float timeBetweenSpawn;
};

