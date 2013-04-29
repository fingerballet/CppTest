#ifndef PLATEAU_H
#define PLATEAU_H

#include "typedef.h"

class Direction;
class Position;

class Plateau
{
public:

	Plateau(WORD width = 0, WORD height = 0): width(width), height(height){}
	Position getNextPosition(const Position& position, const Direction& direction) const;

private:

    bool isBeyondScope(const Position& position) const;

	WORD width;
	WORD height;
};

#endif
