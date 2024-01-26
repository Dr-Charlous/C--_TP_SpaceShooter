#include "BackGround.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

void BackGround::setTexture()
{
	if (!backGroundTexture.loadFromFile("Assets/Shooter/background.png")) {
		std::cout << "Erreur" << std::endl;
	}
	backGroundSprite1.setTexture(backGroundTexture);
	backGroundSprite2.setTexture(backGroundTexture);
	backGroundSprite2.setPosition(0, -Game::WINDOW_HEIGHT);
}

void BackGround::updateTexture(float _timeBetween)
{
	backGroundSprite1.move(0.f, 120.f * _timeBetween);
	if (backGroundSprite1.getPosition().y > (float)Game::WINDOW_HEIGHT)
		backGroundSprite1.setPosition(0, -(float)backGroundSprite1.getPosition().y);

	backGroundSprite2.move(0.f, 120.f * _timeBetween);
	if (backGroundSprite2.getPosition().y > (float)Game::WINDOW_HEIGHT)
		backGroundSprite2.setPosition(0, -(float)backGroundSprite2.getPosition().y);
}

void BackGround::drawBackGround(sf::RenderWindow &_window)
{
	_window.draw(backGroundSprite1);
	_window.draw(backGroundSprite2);
}
