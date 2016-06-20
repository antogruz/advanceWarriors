#include <gtest/gtest.h>

#include "map.h"

class MapF : public ::testing::Test {
protected:
	Map<int> map;
public:
	MapF() : map(-1) {}
};


TEST_F(MapF, shouldReturnAttachedData)
{
	map.attach(3, 0, 0);

	ASSERT_EQ(3, map.get(0, 0));
}

TEST_F(MapF, shouldReturnAttachedData2)
{
	map.attach(5, 0, 0);

	ASSERT_EQ(5, map.get(0, 0));
}

TEST_F(MapF, shouldReturnDefaultValue)
{
	ASSERT_EQ(-1, map.get(0, 0));
}

TEST_F(MapF, shouldReturnValueInSpotAsked)
{
	map.attach(2, 0, 0);
	map.attach(3, 1, 1);

	ASSERT_EQ(2, map.get(0, 0));
}

TEST_F(MapF, shouldReturnRightValueInSameLine)
{
	map.attach(2, 0, 0);
	map.attach(3, 0, 1);

	ASSERT_EQ(2, map.get(0, 0));
}

TEST_F(MapF, shouldNotAllowMultipleAttachOnSameSpot)
{
	map.attach(2, 0, 1);
	ASSERT_THROW(map.attach(5, 0, 1), std::invalid_argument);
}

TEST_F(MapF, shouldRemoveElement)
{
	map.attach(2, 0, 1);
	map.remove(0, 1);

	ASSERT_EQ(-1, map.get(0, 1));
}

TEST_F(MapF, shouldNotAllowRemoveNotAttach)
{
	ASSERT_THROW(map.remove(0, 0), std::invalid_argument);
}

TEST_F(MapF, shouldNotAllowDoubleRemove)
{
	map.attach(5, 0, 0);
	map.remove(0, 0);

	ASSERT_THROW(map.remove(0, 0), std::invalid_argument);
}

TEST_F(MapF, shouldAllowUseOfRemovedSpot)
{
	map.attach(5, 0, 0);
	map.remove(0, 0);
	map.attach(3, 0, 0);

	EXPECT_EQ(3, map.get(0, 0));
	ASSERT_NO_THROW(map.remove(0,0));
}
