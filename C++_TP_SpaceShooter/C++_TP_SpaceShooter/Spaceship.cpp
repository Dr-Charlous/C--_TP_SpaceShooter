#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& _objectsInScene, std::vector<GameObject*>& objectsToAdd) :
	GameObject(_nameClass, _x, _y, _spriteLocation, objectsInScene, objectsToAdd),
	timeBetweenFire(1)
{
}