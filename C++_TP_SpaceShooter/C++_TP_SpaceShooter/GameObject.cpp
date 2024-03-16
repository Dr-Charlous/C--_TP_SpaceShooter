#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectile.h"

GameObject::GameObject(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& _objectsInScene, std::vector<GameObject*>& _objectsToAdd) :
	nameClass(_nameClass),
	x(_x),
	y(_y),
	spriteLocation(_spriteLocation),
	speed(100),
	timeBetweenFire(0.5f),
    objectsInScene(_objectsInScene),
	objectsToAdd(_objectsToAdd)
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

void GameObject::update(float _time)
{
	spriteSpaceShip.setPosition(x, y);
}

void GameObject::draw(sf::RenderWindow& _window)
{
	_window.draw(spriteSpaceShip);
}

void GameObject::inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsToDelete)
{
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

	collision();
}

void GameObject::fire(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd)
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenFire)
	{
		clock.restart();
		//std::cout << "Fire" << std::endl;
		Projectile* projectile = new Projectile("Projectile", x + textureSpaceShip.getSize().x / 2, y, "Assets/Shooter/laser.png", objectsInScene, objectsToAdd);
		projectile->setSpeed(200);
		projectile->setY(y - projectile->textureSpaceShip.getSize().y);
		objectsToAdd.push_back(projectile);
	}
}

void GameObject::collision()
{
	std::cout << "fdp ta grand mere la chienne" << std::endl;
}
