#pragma once
#include "GameObject.h"

class EnnemyShip : public GameObject
{
public :
	EnnemyShip(std::string _nameClass, float _x, float _y, std::string _spriteLocation);
	void inputs(sf::RenderWindow& _window, sf::Event event, float _time) override;
	void fire() override;

protected:
	sf::Clock clock;
	float timeBetweenFire;
};

