#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ui
{
public:
	Ui(float _x, float _y, int _size);

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setText(std::string text);
	std::string getText();
	
	void setScore(int score);
	int getScore();

	void setSize(int size);
	int getSize();

	void drawText(sf::RenderWindow& window, std::vector<GameObject*>& objectsInScene);
protected :
	int size;
	int score;
	float x;
	float y;
	sf::Font font;
	std::string text;
	sf::Text textDraw;
};

