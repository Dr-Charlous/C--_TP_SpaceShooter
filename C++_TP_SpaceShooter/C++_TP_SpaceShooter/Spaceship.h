#pragma once
class Spaceship
{
protected:
	int x;
	int y;
	int speed;

public:

	Spaceship(int _x, int _y);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	int getSpeed();
	void setSpeed(int speed);

	void right();
	void left();
	void forward();
	void backward();
	void display();
	void fire();
};

