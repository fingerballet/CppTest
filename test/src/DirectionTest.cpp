#include <gtest/gtest.h>
#include "Direction.h"

class DirectionTest : public testing::Test
{
};

TEST_F(DirectionTest, the_left_side_of_north_eq_west_test)
{
    ASSERT_EQ(Direction::N().leftSide(), Direction::W());
}

TEST_F(DirectionTest, the_right_side_of_north_eq_east_test)
{
    ASSERT_EQ(Direction::N().rightSide(), Direction::E());
}

TEST_F(DirectionTest, the_left_side_of_west_eq_sourth_test)
{
    ASSERT_EQ(Direction::W().leftSide(), Direction::S());
}

TEST_F(DirectionTest, the_right_side_of_west_eq_north_test)
{
    ASSERT_EQ(Direction::W().rightSide(), Direction::N());
}

TEST_F(DirectionTest, to_string_of_direction_test)
{
    ASSERT_EQ("N", Direction::N().toString());
    ASSERT_EQ("E", Direction::N().rightSide().toString());
}

TEST_F(DirectionTest, get_direction_by_name_test)
{
    ASSERT_EQ(Direction::E(), Direction::getDirectionByName("E"));
}
