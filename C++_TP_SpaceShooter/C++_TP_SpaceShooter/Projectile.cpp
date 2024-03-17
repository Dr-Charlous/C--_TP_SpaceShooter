#include "Projectile.h"
#include "Game.h"
#include <iostream>

Projectile::Projectile(std::string _nameClass, float _x, float _y, int _hp, std::string _spriteLocation, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd) :
	GameObject(_nameClass, _x, _y, _hp, _spriteLocation, objectsInScene, objectsToAdd)
{
}

void Projectile::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	if (y + textureSpaceShip.getSize().y < 0 || _time > 0 && y - textureSpaceShip.getSize().y - textureSpaceShip.getSize().y > Game::WINDOW_HEIGHT) {
		objectsToDelete.push_back(this);
	}
	else {
		collision(objectsInScene, objectsToDelete);
		forward(_time);
	}
}

void Projectile::collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	if (objectsInScene.size() > 1) {
		int index = 0;
		for (size_t i = 1; i < objectsInScene.size(); i++)
		{
			if (objectsInScene[i]->getNameClass() == nameClass) {
				index = i;
			}
		}

		for (size_t i = 0; i < objectsInScene.size(); i++)
		{
			if (objectsInScene[i]->getNameClass() != nameClass) {
				float x1 = x;
				float x2 = x + textureSpaceShip.getSize().x;
				float x3 = objectsInScene[i]->getX();
				float x4 = objectsInScene[i]->getX() + objectsInScene[i]->textureSpaceShip.getSize().x;
				float y1 = y;
				float y2 = y + textureSpaceShip.getSize().y;
				float y3 = objectsInScene[i]->getY();
				float y4 = objectsInScene[i]->getY() + objectsInScene[i]->textureSpaceShip.getSize().y;

				if (x3 <= x2 && x3 >= x1 && x4 >= x1 && x4 >= x2 && y3 <= y2 && y3 >= y1 && y4 >= y1 && y4 >= y2)
				{
					objectsToDelete.push_back(objectsInScene[index]);

					if (objectsInScene[i]->getHp() > 0)
						objectsInScene[i]->setHp(objectsInScene[i]->getHp() - 1);
					else if (objectsInScene[i]->getHp() <= 0) {
						objectsInScene[i]->explode();
						objectsToDelete.push_back(objectsInScene[i]);
					}
				}
			}
		}
	}
}
