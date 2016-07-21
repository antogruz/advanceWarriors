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

TEST_F(MapF, shouldMoveElement)
{
	map.attach(5, 1, 1);
	map.move(1, 1, 0, 0);

	EXPECT_EQ(-1, map.get(1, 1));
	EXPECT_EQ(5, map.get(0, 0));
}

TEST_F(MapF, moveShouldLeftMapUnchangedOnException)
{
	map.attach(5, 1, 1);
	map.attach(3, 2, 2);

	try {
		map.move(1, 1, 2, 2);
	} catch (std::invalid_argument & e) {
		EXPECT_EQ(3, map.get(2, 2));
		EXPECT_EQ(5, map.get(1, 1));
	}
}

TEST_F(MapF, moveShouldLeftMapUnchangedOnException2)
{
	try {
		map.move(0, 0, 1, 1);
	} catch (std::invalid_argument & e) {
		ASSERT_NO_THROW(map.attach(5, 1, 1));
	}
}

TEST_F(MapF, shouldGetIteratorOnNonEmptyValues)
{
	map.attach(5, 0, 1);
	auto it = map.begin();

	EXPECT_EQ(5, it->second);
	EXPECT_EQ(0, it->first.first);
	EXPECT_EQ(1, it->first.second);
}

TEST_F(MapF, shouldGetAllNonEmptyValues)
{
	map.attach(5, 0, 1);
	map.attach(3, 1, 1);
	map.attach(7, 1, 2);

	int sum = 0;
	for(auto it = map.begin(); it != map.end(); it++) {
		sum += it->second;
	}

	ASSERT_EQ(15, sum);
}

TEST_F(MapF, shouldGetMaxRow)
{
	map.attach(3, 1, 3);
	map.attach(2, 2, 2);

	ASSERT_EQ(2, getMaxRow(map));
}

TEST_F(MapF, shouldGetMaxColumn)
{
	map.attach(3, 1, 3);
	map.attach(2, 2, 2);

	ASSERT_EQ(3, getMaxColumn(map));
}


