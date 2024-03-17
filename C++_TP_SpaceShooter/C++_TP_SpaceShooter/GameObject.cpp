#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectile.h"

GameObject::GameObject(std::string _nameClass, float _x, float _y, int _hp, std::string _spriteLocation, std::vector<GameObject*>& _objectsInScene, std::vector<GameObject*>& _objectsToAdd) :
	nameClass(_nameClass),
	x(_x),
	y(_y),
	hp(_hp),
	spriteLocation(_spriteLocation),
	speed(100),
	timeBetweenFire(0.5f),
	objectsInScene(_objectsInScene),
	objectsToAdd(_objectsToAdd),
	hpMax(hp)
{
	if (!textureSpaceShip.loadFromFile(spriteLocation)) {
		std::cout << "Erreur" << std::endl;
	}
	spriteSpaceShip.setTexture(textureSpaceShip);
	spriteSpaceShip.setPosition(x, y);
}

std::string GameObject::getNameClass()
{
	return this->nameClass;
}

void GameObject::setNameClass(std::string nameClass)
{
	this->nameClass = nameClass;
}

float GameObject::getX()
{
	return this->x;
}

void GameObject::setX(float x)
{
	this->x = x;
}

float GameObject::getY()
{
	return this->y;
}

void GameObject::setY(float y)
{
	this->y = y;
}

int GameObject::getHp()
{
	return this->hp;
}

void GameObject::setHp(int hp)
{
	this->hp = hp;
}

float GameObject::getSpeed()
{
	return this->speed;
}

void GameObject::setSpeed(float speed)
{
	this->speed = speed;
}

std::string GameObject::getSpriteName()
{
	return this->spriteLocation;
}

void GameObject::setSpriteName(std::string spriteLocation)
{
	this->spriteLocation = spriteLocation;
}

sf::Sprite& GameObject::getSprite()
{
	return this->spriteSpaceShip;
}

void GameObject::setSprite(sf::Sprite spriteSpaceShip)
{
	this->spriteSpaceShip = spriteSpaceShip;
}

void GameObject::right(float _time)
{
	this->x += speed * _time;
}

void GameObject::left(float _time)
{
	this->x -= speed * _time;
}

void GameObject::forward(float _time)
{
	this->y -= speed * _time;
}

void GameObject::backward(float _time)
{
	this->y += speed * _time;
}

void GameObject::explode()
{
	if (!textureSpaceShip.loadFromFile("Assets/Shooter/spaceship.png")) {
		std::cout << "Erreur" << std::endl;
	}
}

void GameObject::update(float _time)
{
	spriteSpaceShip.setPosition(x, y);
}

void GameObject::draw(sf::RenderWindow& _window)
{
	_window.draw(spriteSpaceShip);
}

void GameObject::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	collision(objectsInScene, objectsToDelete);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x > 0)
	{
		left(_time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x < _window.getSize().x - textureSpaceShip.getSize().x)
	{
		right(_time);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y > 0)
	{
		forward(_time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y < _window.getSize().y - textureSpaceShip.getSize().y)
	{
		backward(_time);
	}

	//std::cout << _window.getSize().x << " : " << _window.getSize().y << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire(objectsInScene, objectsToAdd);
	}
}

void GameObject::fire(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenFire)
	{
		clock.restart();
		Projectile* projectile = new Projectile("Projectile", x + textureSpaceShip.getSize().x / 2, y, 1, "Assets/Shooter/laser.png", objectsInScene, objectsToAdd);
		projectile->setSpeed(300);
		projectile->setY(y - projectile->textureSpaceShip.getSize().y);
		objectsToAdd.push_back(projectile);
	}
}

void GameObject::collision(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToDelete)
{
	/*if (objectsInScene.size() > 0) {
		for (size_t i = 0; i < objectsInScene.size(); i++)
		{
			if (objectsInScene[i]->getNameClass() != "") {
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
 						objectsToDelete.push_back(objectsInScene[0]);
					}
				}
			}
		}
	}*/
}
