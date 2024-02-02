#include "EnnemyShip.h"
#include <iostream>

EnnemyShip::EnnemyShip(std::string _nameClass, float _x, float _y, std::string _spriteLocation) :
	GameObject(_nameClass, _x, _y, _spriteLocation),
	timeBetweenFire(1)
{
}

void EnnemyShip::inputs(sf::RenderWindow& _window, sf::Event event, float _time)
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	//{
	//	left(_time);
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//{
	//	right(_time);
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//{
	//	forward(_time);
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//{
		backward(_time);
	//}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire();
	}
}

void EnnemyShip::fire()
{
	float timeBetween = clock.getElapsedTime().asSeconds();
	if (timeBetween > timeBetweenFire)
	{
		clock.restart();
		std::cout << "Fire" << std::endl;
	}
}