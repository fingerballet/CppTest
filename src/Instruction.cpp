#include "Instruction.h"
#include "Rover.h"

void InstructionL::control(Rover& rover) const
{
	rover.turnTo(rover.getDirection().leftSide());
}

void InstructionR::control(Rover& rover) const
{
	rover.turnTo(rover.getDirection().rightSide());
}

void InstructionM::control(Rover& rover) const
{
	rover.moveTo(rover.landedPlateau.getNextPosition(rover.getPosition(), rover.getDirection()));
}
