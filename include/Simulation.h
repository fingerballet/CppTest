#ifndef EXPLORATIONS_SIMULATION_H
#define EXPLORATIONS_SIMULATION_H

#include <sstream>
#include <iostream>
#include "Plateau.h"
#include "Position.h"
#include "Direction.h"

using std::string;
using std::iostream;
using std::stringstream;

class Simulation
{
public:

	void execute(iostream& input);
	string getOutput();

private:

	void simulateExploration(iostream& input);
	bool endOfSimulation(iostream& input);
	string getInstructionsFromStream(iostream& input);
	Direction getLandDirectionFromStream(iostream& input);
	Position getLandPositionFromStream(iostream& input);
	Plateau getPlateauFromStream(iostream& input);
	void prepare(iostream& input);

	stringstream simulationOutput;
	Plateau landPlateau;
};

#endif
