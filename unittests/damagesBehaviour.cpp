#include <gtest/gtest.h>

#include "damages.h"

TEST(Damages, shouldBeFiveIfEquals)
{
	EXPECT_EQ(5, damages(1, 1));
	ASSERT_EQ(5, damages(3, 3));
}

TEST(Damages, shouldBeTwiceWithDoubleAttack)
{
	ASSERT_EQ(2 * damages(1, 1), damages(2,1));
}

TEST(Damages, shouldBeHalfWithDoubleDefense)
{
	ASSERT_EQ(0.5 * damages(1, 1), damages(1, 2));
}

TEST(Damages, shouldBeAtLeastTenIfNullDefenseAndPositiveAttack)
{
	ASSERT_GE(10, damages(3, 0));
}

TEST(Damages, shouldAlwaysBeNullIfNoAttack)
{
	EXPECT_EQ(0, damages(0, 0));
}
