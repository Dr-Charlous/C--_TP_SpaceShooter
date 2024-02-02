#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(std::string _nameClass, float _x, float _y, std::string _spriteLocation) :
	GameObject(_nameClass, _x, _y, _spriteLocation),
	timeBetweenFire(1)
{
}