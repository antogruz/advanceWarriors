#include <math.h>

#include "unit.h"

Unit::Unit(int power)
{
	this->power = power;
	health = 10.0;
}

int Unit::getHealth() const
{
	return ceil(health);
}

float Unit::getDamage() const
{
	return float(getHealth() * power) / 10;
}

void Unit::hit(Unit & opponent)
{
	opponent.health -= getDamage();
	if (opponent.health < 0)
		opponent.health = 0;
}

