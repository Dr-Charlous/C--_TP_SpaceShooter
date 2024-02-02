#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Spaceship : public GameObject
{
public:
	Spaceship(float _x, float _y, std::string _spriteLocation);
	void inputs(sf::Event event, float _time);
	void fire();

protected:
	sf::Clock clock;
	float timeBetweenFire;
};

