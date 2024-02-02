#pragma once
#include <SFML/Graphics.hpp>
class Spaceship
{
public:
	Spaceship(float _x, float _y);

	float getX();
	void setX(float x);

	float getY();
	void setY(float y);

	float getSpeed();
	void setSpeed(float speed);

	void right(float _time);
	void left(float _time);
	void forward(float _time);
	void backward(float _time);
	void display(sf::Event event, float _time);
	void update(float _time);
	void draw(sf::RenderWindow &_window);
	void fire();

protected:
	float x;
	float y;
	float speed;
	sf::Texture textureSpaceShip;
	sf::Sprite spriteSpaceShip;
};

