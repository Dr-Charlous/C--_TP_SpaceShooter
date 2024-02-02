#include "EnnemyShip.h"
#include <iostream>

EnnemyShip::EnnemyShip(std::string _nameClass, float _x, float _y, std::string _spriteLocation) :
	GameObject(_nameClass, _x, _y, _spriteLocation)
{
}
