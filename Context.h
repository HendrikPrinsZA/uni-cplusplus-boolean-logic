#ifndef CONTEXT_H
#define CONTEXT_H
#include <string>

class VariableExpression;

class Context
{
public:
    explicit Context(void);
    virtual ~Context(void);

    bool Lookup(const char*) const;
    void AssignW(VariableExpression*, bool);
    void AssignX(VariableExpression*, bool);
	void AssignY(VariableExpression*, bool);
    void AssignZ(VariableExpression*, bool);

private:
    char* wName;
    char* xName;
	char* yName;
    char* zName;
	 
	
    bool wValue;
    bool xValue;
	bool yValue;
    bool zValue;
};
#endif


