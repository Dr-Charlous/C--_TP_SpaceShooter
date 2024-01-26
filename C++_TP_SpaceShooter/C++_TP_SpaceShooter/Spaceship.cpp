#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(float _x, float _y) :
	x(_x),
	y(_y),
	speed(10)
{
	if (!textureSpaceShip.loadFromFile("Assets/Shooter/spaceship.png")) {
		std::cout << "Erreur" << std::endl;
	}
	spriteSpaceShip.setTexture(textureSpaceShip);
	spriteSpaceShip.setPosition(x, y);
}

int Spaceship::getX()
{
	return this->x;
}

void Spaceship::setX(float x)
{
	this->x = x;
}

int Spaceship::getY()
{
	return this->y;
}

void Spaceship::setY(float y)
{
	this->y = y;
}

int Spaceship::getSpeed()
{
	return this->speed;
}

void Spaceship::setSpeed(int speed)
{
	this->speed = speed;
}

void Spaceship::right()
{
	this->x+= speed;
}

void Spaceship::left()
{
	this->x-= speed;
}

void Spaceship::forward()
{
	this->y-=speed;
}

void Spaceship::backward()
{
	this->y+=speed;
}

void Spaceship::display(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			left();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			right();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			forward();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			backward();
		}
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