#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(std::string _nameClass, float _x, float _y, std::string _spriteLocation, std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& _objectsToAdd);
	std::string nameClass;

	std::string getNameClass();
	void setNameClass(std::string nameClass);

	float getX();
	void setX(float x);

	float getY();
	void setY(float y);

	float getSpeed();
	void setSpeed(float speed);

	std::string getSpriteName();
	void setSpriteName(std::string spriteLocation);

	sf::Sprite& getSprite();
	void setSprite(sf::Sprite spriteSpaceShip);

	void right(float _time);
	void left(float _time);
	void forward(float _time);
	void backward(float _time);

	void update(float _time);
	void draw(sf::RenderWindow& _window);

	virtual void inputs(sf::RenderWindow& _window, sf::Event event, float _time, std::vector<GameObject*>& objectsToDelete);
	virtual void fire(std::vector<GameObject*>& objectsInScene, std::vector<GameObject*>& objectsToAdd);
	virtual void collision();

	sf::Texture textureSpaceShip;
	std::vector<GameObject*>& objectsInScene;
	std::vector<GameObject*>& objectsToAdd;
protected:
	float x;
	float y;
	float speed;
	std::string spriteLocation;
	sf::Sprite spriteSpaceShip;
	sf::Clock clock;
	float timeBetweenFire;
};

