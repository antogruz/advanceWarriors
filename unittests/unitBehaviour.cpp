#include <gtest/gtest.h>

#include "unit.h"

TEST(Unit, shouldBeComplete)
{
	Unit man;

	ASSERT_EQ(10, man.getHealth());
}

TEST(Unit, shouldHarmOpponent)
{
	Unit man, opponent;

	man.hit(opponent);

	ASSERT_NE(10, opponent.getHealth());
}

TEST(Unit, shouldInflictItsDamagesToOpponent)
{
	Unit man(2), opponent;

	man.hit(opponent);

	ASSERT_EQ(8, opponent.getHealth());
}

TEST(Unit, shouldInflict3DamagesToOpponent)
{
	Unit man(3), opponent;

	man.hit(opponent);

	ASSERT_EQ(7, opponent.getHealth());
}

TEST(Unit, shouldNotHaveNegativeHealth)
{
	Unit man(6), opponent;

	man.hit(opponent);
	man.hit(opponent);

	ASSERT_EQ(0, opponent.getHealth());
}

TEST(Unit, shouldInflictLessDamageWhenInjured)
{
	Unit man(5), opponent(5);

	man.hit(opponent);
	opponent.hit(man);

	ASSERT_LT(opponent.getHealth(), man.getHealth());
}

TEST(Unit, shouldInflictHalfDamageIfHalfHealth)
{
	Unit man(5), opponent(5);

	man.hit(opponent);
	opponent.hit(man);
	opponent.hit(man);

	ASSERT_EQ(man.getHealth(), opponent.getHealth());
}

