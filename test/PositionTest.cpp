#include <gtest/gtest.h>
#include "Position.h"
#include "Direction.h"

class PositionTest : public testing::Test
{
};

TEST_F(PositionTest, to_string_of_position_test)
{
    ASSERT_EQ("1 2", Position(1 ,2).toString());
}

TEST_F(PositionTest, get_the_north_position_test)
{
    ASSERT_EQ(Position(1, 3), Position(1 ,2).getNeighborBy(Direction::N()));
}

TEST_F(PositionTest, get_the_south_position_test)
{
    ASSERT_EQ(Position(1, 1), Position(1 ,2).getNeighborBy(Direction::S()));
}

TEST_F(PositionTest, get_the_east_position_test)
{
    ASSERT_EQ(Position(2, 2), Position(1 ,2).getNeighborBy(Direction::E()));
}

TEST_F(PositionTest, get_the_west_position_test)
{
    ASSERT_EQ(Position(0, 2), Position(1 ,2).getNeighborBy(Direction::W()));
}

