#include "Variable.h"

VariableExpression::VariableExpression(const char* name)
{
    _name = _strdup(name);
}

VariableExpression::~VariableExpression(void)
{
	//HELPstd::cout << "variable deleted" << std::endl;
}

bool VariableExpression::Evaluate(Context& aContext)
{
    return aContext.Lookup(_name);
}

char* VariableExpression::getName()
{
    return _name;
}

