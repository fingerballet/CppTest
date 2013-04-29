#include "Direction.h"

const string Direction::DIRECTIONS[MAX_DIRECTION_NUM] = {"N", "E", "S", "W"};

bool Direction::operator==(const Direction& another) const
{
	return (this->value == another.value);
}

Direction Direction::rightSide() const
{
	return Direction((this->value + 1) % MAX_DIRECTION_NUM);
}

Direction Direction::leftSide() const
{
	return Direction((this->value + 3) % MAX_DIRECTION_NUM);
}

Direction Direction::getDirectionByName(const string& directionName)
{
    for(WORD index = 0; index < MAX_DIRECTION_NUM; index++)
    {
    	if(DIRECTIONS[index] == directionName)  return Direction(index);
    }
	return Direction::N();
}

string Direction::toString() const
{
	return DIRECTIONS[value];
}
