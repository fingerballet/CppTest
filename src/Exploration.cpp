#include "typedef.h"
#include "Rover.h"
#include "Exploration.h"
#include "Instructions.h"

void Exploration::execute(const Position&  landPosition,
			 const Direction& landDirection,
			 const Instructions&    instructions)
{
	prepare(landPosition, landDirection);
	explore(instructions);
}

void Exploration::prepare(const Position&  landPosition, const Direction& landDirection)
{
	marsRover.landOn(landPlateau, landPosition, landDirection);
}

void Exploration::explore(const Instructions& instructions)
{
	for(WORD index = 0; index < instructions.size(); index++)
	{
		marsRover.execute(instructions[index]);
	}
}
