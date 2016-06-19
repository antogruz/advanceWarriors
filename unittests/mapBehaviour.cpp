#include <gtest/gtest.h>

#include "map.h"

TEST(Map, shouldReturnAttachedData)
{
	Map<int> map(10, 10, 0);
	map.attach(3, 0, 0);

	ASSERT_EQ(3, map.get(0, 0));
}

TEST(Map, shouldReturnAttachedData2)
{
	Map<int> map(10, 10, 0);
	map.attach(5, 0, 0);

	ASSERT_EQ(5, map.get(0, 0));
}

TEST(Map, shouldReturnDefaultValue)
{
	Map<int> map(10, 10, -1);

	ASSERT_EQ(-1, map.get(0, 0));
}

TEST(Map, shouldReturnValueInSpotAsked)
{
	Map<int> map(10, 10, -1);

	map.attach(2, 0, 0);
	map.attach(3, 1, 1);

	ASSERT_EQ(2, map.get(0, 0));
}

TEST(Map, shouldReturnRightValueInSameLine)
{
	Map<int> map(10, 10, -1);

	map.attach(2, 0, 0);
	map.attach(3, 0, 1);

	ASSERT_EQ(2, map.get(0, 0));
}
