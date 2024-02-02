#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Spaceship : public GameObject
{
public:
	Spaceship(std::string _nameClass, float _x, float _y, std::string _spriteLocation);

protected:
	sf::Clock clock;
	float timeBetweenFire;
};

