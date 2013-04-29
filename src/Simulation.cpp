#include "Simulation.h"
#include "typedef.h"
#include "Rover.h"
#include "Exploration.h"
#include "Instructions.h"

using std::endl;

Plateau Simulation::getPlateauFromStream(iostream& input)
{
	WORD plateauWidth = 0;
	WORD plateauHeight = 0;
	input >> plateauWidth >> plateauHeight;
	return Plateau(plateauWidth, plateauHeight);
}

Position Simulation::getLandPositionFromStream(iostream& input)
{
	WORD landPositionX = 0;
	WORD landPositionY = 0;
	input >> landPositionX >> landPositionY;
	return Position(landPositionX, landPositionY);
}

Direction Simulation::getLandDirectionFromStream(iostream& input)
{
	string directionName = "N";
	input >> directionName;
	return Direction::getDirectionByName(directionName);
}

string Simulation::getInstructionsFromStream(iostream& input)
{
	string instructions = "";
	input >> instructions;
	return instructions;
}

bool Simulation::endOfSimulation(iostream& input)
{
	return input.eof();
}

void Simulation::simulateExploration(iostream& input)
{
	Rover marsRover;
	Position landPosition = getLandPositionFromStream(input);
	Direction landDirection = getLandDirectionFromStream(input);
	string instructionsStr = getInstructionsFromStream(input);
	Exploration(marsRover, landPlateau).execute(landPosition, landDirection, Instructions(instructionsStr));
	simulationOutput << marsRover.toString() << endl;
}

void Simulation::prepare(iostream& input)
{
	simulationOutput.str("");
	landPlateau = getPlateauFromStream(input);
}

void Simulation::execute(iostream& input)
{
	prepare(input);

	do{
        simulateExploration(input);
	}while(!endOfSimulation(input));
}

string Simulation::getOutput()
{
	return simulationOutput.str();
}

