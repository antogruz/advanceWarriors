#include <math.h>

#include "unit.h"
#include "damages.h"

Unit::Unit(int att, int def)
{
	health = 10.0;
	this->att = att;
	this->def = def;
}

int Unit::getHealth() const
{
	return ceil(health);
}

void Unit::hit(Unit & opponent)
{
	opponent.getInjured(float(getHealth()) / 10.0 * damages(att, opponent.def));
}

void Unit::getInjured(float damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}
