#pragma once
#include <SFML/Graphics.hpp>

class BackGround
{
public:
	void setTexture();
	void update(float _timeBetween);
	void draw(sf::RenderWindow &_window);
protected:
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite1;
	sf::Sprite backGroundSprite2;
};

