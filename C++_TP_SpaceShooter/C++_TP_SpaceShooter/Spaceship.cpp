#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(float _x, float _y) :
	x(_x),
	y(_y),
	speed(1000)
{
	if (!textureSpaceShip.loadFromFile("Assets/Shooter/spaceship.png")) {
		std::cout << "Erreur" << std::endl;
	}
	spriteSpaceShip.setTexture(textureSpaceShip);
	spriteSpaceShip.setPosition(x, y);
}

float Spaceship::getX()
{
	return this->x;
}

void Spaceship::setX(float x)
{
	this->x = x;
}

float Spaceship::getY()
{
	return this->y;
}

void Spaceship::setY(float y)
{
	this->y = y;
}

float Spaceship::getSpeed()
{
	return this->speed;
}

void Spaceship::setSpeed(float speed)
{
	this->speed = speed;
}

void Spaceship::right(float _time)
{
	this->x += speed * _time;
}

void Spaceship::left(float _time)
{
	this->x -= speed * _time;
}

void Spaceship::forward(float _time)
{
	this->y -= speed * _time;
}

void Spaceship::backward(float _time)
{
	this->y += speed * _time;
}

void Spaceship::display(sf::Event event, float _time)
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

void Spaceship::update(float _time)
{
	spriteSpaceShip.setPosition(x, y);
}

void Spaceship::draw(sf::RenderWindow &_window)
{
	_window.draw(spriteSpaceShip);
}

void Spaceship::fire()
{
	std::cout << "Fire" << std::endl;
}