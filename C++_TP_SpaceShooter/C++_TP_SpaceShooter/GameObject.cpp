#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(float _x, float _y, std::string _spriteLocation) :
	x(_x),
	y(_y),
	spriteLocation(_spriteLocation),
	speed(100)
{
	if (!textureSpaceShip.loadFromFile(spriteLocation)) {
		std::cout << "Erreur" << std::endl;
	}
	spriteSpaceShip.setTexture(textureSpaceShip);
	spriteSpaceShip.setPosition(x, y);
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

std::string GameObject::getSprite()
{
	return this->spriteLocation;
}

void GameObject::setSprite(std::string spriteLocation)
{
	this->spriteLocation = spriteLocation;
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

void GameObject::inputs(sf::Event event, float _time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		left(_time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		right(_time);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		forward(_time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		backward(_time);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire();
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

void GameObject::fire()
{
	std::cout << "Fire" << std::endl;
}