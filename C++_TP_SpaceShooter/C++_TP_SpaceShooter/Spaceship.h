#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Spaceship : public GameObject
{
public:
	Spaceship(float _x, float _y, std::string _spriteLocation);
};

