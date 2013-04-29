#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include "typedef.h"

using std::string;

#define DEFINE_DIRECTION(directionName, value) \
static Direction directionName()\
{\
	return Direction(value);\
}\

class Direction
{
public:

	DEFINE_DIRECTION(N, 0);
	DEFINE_DIRECTION(E, 1);
	DEFINE_DIRECTION(S, 2);
	DEFINE_DIRECTION(W, 3);

	static Direction getDirectionByName(const string& directionName);
	bool operator==(const Direction& another) const;
	Direction rightSide() const;
	Direction leftSide() const;
	string toString() const;

private:

    explicit Direction(WORD value):value(value){}

    WORD value;

    const static WORD MAX_DIRECTION_NUM = 4;
    const static string DIRECTIONS[MAX_DIRECTION_NUM];
};

#endif
