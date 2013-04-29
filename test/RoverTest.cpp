/*
 * RoverTest.cpp
 *
 *  Created on: 2013-4-2
 *      Author: administrator
 */

#include <gtest/gtest.h>
#include "Position.h"
#include "Direction.h"
#include "Plateau.h"
#include "Instruction.h"
#include "Rover.h"

class RoverTest : public testing::Test
{

protected:
    Rover rover;
};

TEST_F(RoverTest, default_position_of_rover_test)
{
    ASSERT_EQ(Position(0, 0), rover.getPosition());
}

TEST_F(RoverTest, default_direction_of_rover_test)
{
    ASSERT_EQ(Direction::N(), rover.getDirection());
}

TEST_F(RoverTest, string_interface_of_rover_test)
{
    ASSERT_EQ("0 0 N", rover.toString());
}

TEST_F(RoverTest, default_rover_could_not_move_forward_test)
{
	rover.execute(InstructionM());
    ASSERT_EQ(Position(0, 0), rover.getPosition());
}

TEST_F(RoverTest, rover_turn_right_test)
{
	rover.execute(InstructionR());
    ASSERT_EQ(Direction::E(), rover.getDirection());
}

TEST_F(RoverTest, rover_turn_left_test)
{
	rover.execute(InstructionL());
    ASSERT_EQ(Direction::W(), rover.getDirection());
}

TEST_F(RoverTest, rover_land_on_normal_position_of_plateau_test)
{
	rover.landOn(Plateau(5,5), Position(1,2), Direction::S());
    ASSERT_EQ(Direction::S(), rover.getDirection());
    ASSERT_EQ(Position(1,2), rover.getPosition());
}

TEST_F(RoverTest, rover_move_toward_north_direction_on_plateau_test)
{
	rover.landOn(Plateau(5,5), Position(1,2), Direction::N());
	rover.execute(InstructionM());
    ASSERT_EQ(Position(1,3), rover.getPosition());
}




