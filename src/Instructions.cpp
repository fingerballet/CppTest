#include "Instructions.h"
#include "Instruction.h"

//////////////////////////////////////////////////////////////////////////
#define BEGIN_INSTRUCTION_ITEM(item) \
if( #item == instructStr ) \
{ \
	instructions.push_back(new Instruction##item()); \
}

#define INSTRUCTION_ITEM(item) \
else if( #item == instructStr ) \
{ \
	instructions.push_back(new Instruction##item()); \
}

#define END_INSTRUCTION_ITEM(item) \
INSTRUCTION_ITEM(item)\
else{}

///////////////////////////////////////////////////////////////////////////

void Instructions::add(const string& instructStr)
{
	BEGIN_INSTRUCTION_ITEM(L)
		  INSTRUCTION_ITEM(R)
	  END_INSTRUCTION_ITEM(M)
}

Instructions::Instructions(const string& instructsStr)
{
    for( string::const_iterator it = instructsStr.begin(); it != instructsStr.end(); ++it )
    {
        add(string().insert(0,1,*it));
    }
}

Instruction& Instructions::operator[](WORD index) const
{
	return *(instructions[index]);
}

WORD Instructions::size() const
{
	return instructions.size();
}

void Instructions::clear()
{
	for (WORD index = 0; index < instructions.size(); index++)
	{
		delete instructions[index];
	}
	instructions.clear();
}

Instructions::~Instructions()
{
	clear();
}
