#ifndef VARIABLEEXPRESSION_H
#define VARIABLEEXPRESSION_H
#include "Context.h"
#include "BooleanExpression.h"
//class Context;

class VariableExpression : public BooleanExpression
{
public:
    explicit VariableExpression(const char*);
    virtual ~VariableExpression();

    virtual bool Evaluate(Context&);
    char* getName();
	char getType(){return 'V';};
	char getVar(){return _name[0];};

private:
    char* _name;
};
#endif


