#ifndef MARS_EXPORATION_H
#define MARS_EXPORATION_H

#include <string>

using std::string;

class Plateau;
class Position;
class Direction;
class Rover;
class Instructions;

class Exploration
{
public:

	Exploration(Rover& rover, const Plateau& landPlateau)
	               :marsRover(rover),landPlateau(landPlateau)
	{}

	void execute(const Position&  landPosition,
	             const Direction& landDirection,
	             const Instructions&    instructions);

private:

	void prepare(const Position&  landPosition,
			                const Direction& landDirection);
	void explore(const Instructions& instructions);

	Rover& marsRover;
	const Plateau& landPlateau;
};

#endif
