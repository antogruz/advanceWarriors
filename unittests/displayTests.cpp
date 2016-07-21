#include <gtest/gtest.h>

#include "display.h"

TEST(displayMap, small)
{
	Map<Unit*> map(NULL);
	Unit *unit = new(Unit);
	map.attach(unit, 2, 3);
	display(map);
}

