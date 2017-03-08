#include "Variable.h"
#include "Context.h"


Context::Context(void)
{
}

Context::~Context(void)
{
	/*delete w;
	cout << "DELETED W" << endl;
	delete x;
	cout << "DELETED X" << endl;
	delete y;
	cout << "DELETED Y" << endl;
	delete z;
	cout << "DELETED Z" << endl;
	
	wName = NULL;
	xName = NULL;
	yName = NULL;
	zName = NULL;*/
}

bool Context::Lookup(const char* paramName) const
{	
	if (strcmp(wName, paramName) == 0)
	{
		return wValue;
	}else if (strcmp(xName, paramName) == 0)
	{
		return xValue;
	}else if (strcmp(yName, paramName) == 0)
	{
		return yValue;
	}else if (strcmp(zName, paramName) == 0)
	{
		return zValue;
	}
    return false;
}
void Context::AssignW(VariableExpression* anExpression, bool wBoolValue)
{
    wValue = wBoolValue;
    wName = anExpression->getName();
}
void Context::AssignX(VariableExpression* anExpression, bool xBoolValue)
{
    xValue = xBoolValue;
    xName = anExpression->getName();
}
void Context::AssignY(VariableExpression* anExpression, bool yBoolValue)
{
    yValue = yBoolValue;
    yName = anExpression->getName();
}
void Context::AssignZ(VariableExpression* anExpression, bool zBoolValue)
{
    zValue = zBoolValue;
    zName = anExpression->getName();
}



