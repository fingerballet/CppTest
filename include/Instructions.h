#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <vector>
#include <string>
#include "typedef.h"

using std::string;
class Instruction;

class Instructions
{
public:
	Instructions(const string& instructs);
	~Instructions();
	WORD size() const;
	Instruction& operator[](WORD index) const;
private:
	Instructions(const Instructions&);
	bool operator=(const Instructions&) const;

	void add(const string& instrName);
	void clear();

	typedef std::vector<Instruction*> InstrucionList;
	InstrucionList instructions;
};

#endif
