#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "Simulation.h"

using std::endl;

class SimulationTest: public testing::Test
{
protected:
	Simulation simulation;
	stringstream input;
};

TEST_F(SimulationTest, main_process_test)
{
	input << "5 5" << endl
		  << "1 2 N" << endl
		  << "LMLMLMLMM" << endl
		  << "3 3 E" << endl
		  << "MMRMMRMRRM";

	simulation.execute(input);

	ASSERT_EQ("1 3 N\n5 1 E\n", simulation.getOutput());
}
