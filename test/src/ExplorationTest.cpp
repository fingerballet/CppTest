#include <gtest/gtest.h>
#include "Exploration.h"
#include "Rover.h"
#include "Plateau.h"
#include "Position.h"
#include "Direction.h"
#include "Instructions.h"

class ExplorationTest : public testing::Test
{
protected:
	virtual void SetUp()
	{
		marsRover = new Rover();
		landPlateau = new Plateau(5, 5);
		exploration = new Exploration(*marsRover, *landPlateau);
	}

	virtual void TearDown()
	{
		delete exploration;
		delete landPlateau;
		delete marsRover;
	}

	Rover *marsRover;
	Plateau *landPlateau;
	Exploration *exploration;
};

TEST_F(ExplorationTest, exploration_test1)
{
    exploration->execute(Position(1,2),
    		             Direction::N(),
    		             Instructions("LMLMLMLMM"));

    ASSERT_EQ(Position(1,3), marsRover->getPosition());
    ASSERT_EQ(Direction::N(), marsRover->getDirection());

}

TEST_F(ExplorationTest, exploration_test2)
{
    exploration->execute(Position(3, 3),
    		             Direction::E(),
    		             Instructions("MMRMMRMRRM"));

    ASSERT_EQ(Position(5,1), marsRover->getPosition());
    ASSERT_EQ(Direction::E(), marsRover->getDirection());
}
