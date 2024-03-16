#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& _objectsInScene, std::vector<GameObject*>& objectsToAdd) :
	GameObject(_nameClass, _x, _y, _spriteLocation, objectsInScene, objectsToAdd),
	timeBetweenFire(1)
{
}

void Spaceship::collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	if (objectsInScene.size() > 1) {
		for (size_t i = 1; i < objectsInScene.size(); i++)
		{
			if (objectsInScene[i]->getNameClass() != "SpaceShip") {
				float x1 = x;
				float x2 = x + textureSpaceShip.getSize().x;
				float x3 = objectsInScene[i]->getX();
				float x4 = objectsInScene[i]->getX() + objectsInScene[i]->textureSpaceShip.getSize().x;
				float y1 = y;
				float y2 = y + textureSpaceShip.getSize().y;
				float y3 = objectsInScene[i]->getY();
				float y4 = objectsInScene[i]->getY() + objectsInScene[i]->textureSpaceShip.getSize().y;

				if (x3 <= x2 && x3 >= x1 && x4 >= x1 && x4 >= x2) {
					if (y3 <= y2 && y3 >= y1 && y4 >= y1 && y4 >= y2)
					{
						objectsToDelete.push_back(objectsInScene[i]);
					}
				}
			}
		}
	}
}