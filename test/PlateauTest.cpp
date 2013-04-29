#include <gtest/gtest.h>
#include "Plateau.h"
#include "Direction.h"
#include "Position.h"

class PlateauTest : public testing::Test
{
};

TEST_F(PlateauTest, get_the_exist_next_position_on_plateau_test)
{
    ASSERT_EQ(Position(1, 3), Plateau(5, 5).getNextPosition(Position(1 ,2), Direction::N()));
}

TEST_F(PlateauTest, return_original_position_if_the_next_position_unexist)
{
    ASSERT_EQ(Position(1, 5), Plateau(5, 5).getNextPosition(Position(1 ,5), Direction::N()));
}
