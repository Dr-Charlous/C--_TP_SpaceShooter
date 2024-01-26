#pragma once
#include <SFML/Graphics.hpp>

class BackGround
{
public:
	void setTexture();
	void updateTexture(float _timeBetween);
	void drawBackGround(sf::RenderWindow &_window);
protected:
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite1;
	sf::Sprite backGroundSprite2;
};

