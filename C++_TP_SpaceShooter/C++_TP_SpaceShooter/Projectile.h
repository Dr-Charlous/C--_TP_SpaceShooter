#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd);
	void inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete) override;
	void collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete) override;
};

