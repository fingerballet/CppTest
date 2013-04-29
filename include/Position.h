#ifndef POSITION_H
#define POSITION_H

#include <string>
#include "typedef.h"

using std::string;

class Direction;

class Position
{
public:

	Position(WORD x = 0, WORD y = 0):x(x), y(y){}
	bool operator==(const Position& another) const;
	Position getNeighborBy(const Direction& direction) const;
	bool inRangeOf(const Position& rangePosition) const;

	string toString() const;

private:

	Position getNeighborInN() const;
	Position getNeighborInS() const;
	Position getNeighborInW() const;
	Position getNeighborInE() const;

	WORD x;
	WORD y;
};

#endif
