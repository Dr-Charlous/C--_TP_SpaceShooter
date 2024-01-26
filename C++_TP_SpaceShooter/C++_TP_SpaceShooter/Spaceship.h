#pragma once
#include <SFML/Graphics.hpp>
class Spaceship
{
public:
	Spaceship(float _x, float _y);

	int getX();
	void setX(float x);

	int getY();
	void setY(float y);

	int getSpeed();
	void setSpeed(int speed);

	void right();
	void left();
	void forward();
	void backward();
	void display(sf::Event event);
	void update(float _time);
	void draw(sf::RenderWindow &_window);
	void fire();

protected:
	float x;
	float y;
	int speed;
	sf::Texture textureSpaceShip;
	sf::Sprite spriteSpaceShip;
};

