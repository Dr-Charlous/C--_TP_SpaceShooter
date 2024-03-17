#include "Ui.h"
#include <SFML/Graphics/Font.hpp>
#include <iostream>

Ui::Ui(float _x, float _y, int _size) :
	x(_x),
	y(_y),
	size(_size),
	text("Score : 0"),
	score(0)
{
	if (!this->font.loadFromFile("Assets/Shooter/squarefont/Square.ttf")) {
		std::cout << "marche pas" << std::endl;
	}
}

void Ui::setX(float x)
{
	this->x = x;
}

float Ui::getX()
{
	return this->x;
}

void Ui::setY(float y)
{
	this->y = y;
}

float Ui::getY()
{
	return this->y;
}

void Ui::setText(std::string text)
{
	this->text = text;
}

std::string Ui::getText()
{
	return this->text;
}

void Ui::setScore(int score)
{
	this->score = score;
}

int Ui::getScore()
{
	return this->score;
}

void Ui::setSize(int size)
{
	this->size = size;
}

int Ui::getSize()
{
	return this->size;
}

void Ui::drawText(sf::RenderWindow& window, std::vector<GameObject*>& objectsInScene)
{
	textDraw.setFont(font);
	textDraw.setCharacterSize(size);
	textDraw.setFillColor(sf::Color::White); 

	text = "Score : " + std::to_string(score) + "\nLifes : " + std::to_string(objectsInScene[0]->getHp());

	textDraw.setString(text);

	textDraw.setPosition(x, y);

	window.draw(textDraw);
}
