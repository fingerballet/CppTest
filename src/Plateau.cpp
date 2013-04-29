#include "Plateau.h"
#include "Position.h"

Position Plateau::getNextPosition(const Position& position, const Direction& direction) const
{
	if( isBeyondScope( position.getNeighborBy(direction)) )
	{
		return position;
	}
	return position.getNeighborBy(direction);
}

bool Plateau::isBeyondScope(const Position& position) const
{
	return !(position.inRangeOf(Position(width, height)));
}

