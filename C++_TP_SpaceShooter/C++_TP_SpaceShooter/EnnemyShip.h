#pragma once
#include "GameObject.h"

class EnnemyShip : public GameObject
{
public :
	EnnemyShip(std::string _nameClass, float _x, float _y, std::string _spriteLocation);
};

