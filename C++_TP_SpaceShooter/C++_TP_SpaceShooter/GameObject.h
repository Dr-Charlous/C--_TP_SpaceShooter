#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual void findTexture(std::string nameFile);
	virtual void setTextureOnSprite();
	virtual void update();
	virtual void render(sf::RenderWindow &_window);

protected:
	int x;
	int y;
	sf::Texture texture;
	sf::Sprite sprite;
};

