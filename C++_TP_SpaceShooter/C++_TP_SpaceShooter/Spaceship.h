#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Spaceship : public GameObject
{
public:
	Spaceship(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd);
	void collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete) override;

protected:
	sf::Clock clock;
	float timeBetweenFire;
};

