#pragma once
#include <SFML/Graphics.hpp>
class Spaceship
{
public:
	Spaceship(int _x, int _y);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	int getSpeed();
	void setSpeed(int speed);

	void right();
	void left();
	void forward();
	void backward();
	void display(sf::Event event);
	void draw(sf::RenderWindow &_window);
	void fire();

protected:
	int x;
	int y;
	int speed;
	sf::Texture textureSpaceShip;
	sf::Sprite spriteSpaceShip;
};

