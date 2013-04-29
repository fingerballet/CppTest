#include <sstream>
#include "Rover.h"
#include "Instruction.h"

using std::stringstream;

const Position& Rover::getPosition() const
{
	return currentPosition;
}

const Direction& Rover::getDirection() const
{
	return currentDirection;
}

void Rover::landOn(const Plateau& plateau,
		           const Position& landedPosition,
		           const Direction& landedDirection)
{
	this->currentDirection = landedDirection;
	this->currentPosition = landedPosition;
	this->landedPlateau = plateau;
}

void Rover::moveTo(const Position& destination)
{
	currentPosition = destination;
}

void Rover::turnTo(const Direction& direction)
{
	currentDirection = direction;
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
