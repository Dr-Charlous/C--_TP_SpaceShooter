#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(int _x, int _y) :
	x(_x),
	y(_y),
	speed(1)
{
}

int Spaceship::getX()
{
	return this->x;
}

void Spaceship::setX(int x)
{
	this->x = x;
}

int Spaceship::getY()
{
	return this->y;
}

void Spaceship::setY(int y)
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
	this->x++;
}

void Spaceship::left()
{
	this->x--;
}

void Spaceship::forward()
{
	this->y--;
}

void Spaceship::backward()
{
	this->y++;
}

void Spaceship::display()
{
	std::cout << "Spaceship on position(" << x << ", " << y << ")" << std::endl;
}

void Spaceship::fire()
{
	std::cout << "Fire" << std::endl;
}