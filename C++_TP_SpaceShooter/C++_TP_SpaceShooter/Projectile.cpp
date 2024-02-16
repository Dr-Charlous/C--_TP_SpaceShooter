#include "Projectile.h"
#include "Game.h"
#include <iostream>

Projectile::Projectile(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd) :
	GameObject(_nameClass, _x, _y, _spriteLocation, objectsInScene, objectsToAdd)
{
}

void Projectile::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsToDelete)
{
	if ( y + textureSpaceShip.getSize().y < 0 || _time > 0 && y - textureSpaceShip.getSize().y - textureSpaceShip.getSize().y > Game::WINDOW_HEIGHT) {
		std::cout << "End" << std::endl;
		objectsToDelete.push_back(this);
	}
	else {
		forward(_time);
	}
}