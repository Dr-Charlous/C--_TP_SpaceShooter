#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void GameObject::findTexture(std::string nameFile)
{
	std::string folderPath = "Assets/Shooter/" + nameFile + ".png";
	if (!texture.loadFromFile(folderPath)) {
		std::cout << "Erreur" << std::endl;
	}
	setTextureOnSprite();
}

void GameObject::setTextureOnSprite()
{
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void GameObject::update()
{
}

void GameObject::render(sf::RenderWindow& _window)
{
	_window.draw(sprite);
}