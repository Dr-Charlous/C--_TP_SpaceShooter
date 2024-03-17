#pragma once
#include "GameObject.h"

class EnnemyShip : public GameObject
{
public :
	EnnemyShip(std::string _nameClass, float _x, float _y, int _hp, std::string _spriteLocation, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd);
	void inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete) override;
	void fire(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd) override;
	void collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete) override;

	int scoreGiven;
protected:
	sf::Clock clock;
	float timeBetweenFire;
};

