#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float _x, float _y, std::string _spriteLocation);

	float getX();
	void setX(float x);

	float getY();
	void setY(float y);

	float getSpeed();
	void setSpeed(float speed);
	
	std::string getSprite();
	void setSprite(std::string spriteLocation);

	void right(float _time);
	void left(float _time);
	void forward(float _time);
	void backward(float _time);

	void update(float _time);
	void draw(sf::RenderWindow& _window);

protected:
	float x;
	float y;
	float speed;
	std::string spriteLocation;
	sf::Texture textureSpaceShip;
	sf::Sprite spriteSpaceShip;
};

