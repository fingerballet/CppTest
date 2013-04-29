#include <sstream>
#include "Position.h"
#include "Direction.h"

using std::stringstream;

#define RETRUN_NEXT_POSITION_WHEN_DIRECTION_IS(X) \
if (direction == Direction::X()) \
{ \
	return this->getNeighborIn##X(); \
}

Position Position::getNeighborBy(const Direction& direction) const
{
	RETRUN_NEXT_POSITION_WHEN_DIRECTION_IS(N)
	RETRUN_NEXT_POSITION_WHEN_DIRECTION_IS(S)
	RETRUN_NEXT_POSITION_WHEN_DIRECTION_IS(E)
	RETRUN_NEXT_POSITION_WHEN_DIRECTION_IS(W)
	return *this;
}

bool Position::operator==(const Position& another) const
{
	return ((this->x == another.x)&&(this->y == another.y));
}

bool Position::inRangeOf(const Position& rangePosition) const
{
	return ((x <= rangePosition.x) && (y <= rangePosition.y));
}

Position Position::getNeighborInN() const
{
	return Position(x, (y + 1));
}

Position Position::getNeighborInS() const
{
	return Position(x, (y - 1));
}

Position Position::getNeighborInW() const
{
	return Position((x - 1), y);
}

Position Position::getNeighborInE() const
{
	return Position((x + 1), y);
}

string Position::toString() const
{
	stringstream sstream;
	sstream << this->x << " " << this->y;
	return sstream.str();
}
