#include <sstream>
#include "Rover.h"
#include "Instruction.h"

using std::stringstream;

const Position& Rover::getPosition() const
{
	return landPosition;
}

const Direction& Rover::getDirection() const
{
	return landDirection;
}

void Rover::landOn(const Plateau& plateau,
		           const Position& landedPosition,
		           const Direction& landedDirection)
{
	this->landDirection = landedDirection;
	this->landPosition = landedPosition;
	this->landPlateau = plateau;
}

void Rover::moveTo(const Position& destination)
{
	landPosition = destination;
}

void Rover::turnTo(const Direction& direction)
{
	landDirection = direction;
}

void Rover::execute(const Instruction& instr)
{
    instr.control(*this);
}

string Rover::toString() const
{
	stringstream sstream;
	sstream << getPosition().toString() << " " << getDirection().toString();
	return sstream.str();
}
