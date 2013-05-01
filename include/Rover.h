#ifndef ROVER_H
#define ROVER_H

#include <string>
#include "Position.h"
#include "Plateau.h"
#include "Direction.h"
#include "Instruction.h"

using std::string;
class Instruction;

#define REGIST_EXECUTABLE_INSTRUCTION(name)  friend class Instruction##name

class Rover
{
public:

	Rover():landPosition(Position(0 ,0)),
			landDirection(Direction::N()),
			landPlateau(Plateau(0, 0)){}

	void landOn(const Plateau& plateau,
			    const Position& landedPosition = Position(0, 0),
			    const Direction& landedDirection = Direction::N());

	const Position& getPosition() const;
	const Direction& getDirection() const;
	string toString() const;

	void execute(const Instruction& instr);

	REGIST_EXECUTABLE_INSTRUCTION(L);
	REGIST_EXECUTABLE_INSTRUCTION(R);
	REGIST_EXECUTABLE_INSTRUCTION(M);

private:

	void moveTo(const Position& destination);
	void turnTo(const Direction& direction);

	Position landPosition;
	Direction landDirection;
	Plateau landPlateau;
};

#endif
