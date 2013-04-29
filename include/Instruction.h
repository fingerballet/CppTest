#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Rover;

class Instruction
{
public:
	virtual ~Instruction(){}
protected:
	friend class Rover;
	virtual void control(Rover& rover) const = 0;
};

#define DECLARE_INSTRUCTION(name) \
class Instruction##name : public Instruction \
{ \
private: \
	virtual void control(Rover& rover) const; \
};

DECLARE_INSTRUCTION(L)
DECLARE_INSTRUCTION(R)
DECLARE_INSTRUCTION(M)

#endif
