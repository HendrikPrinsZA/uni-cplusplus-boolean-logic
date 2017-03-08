#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H
#include <iostream>

class Context;

class BooleanExpression
{
public:
    explicit BooleanExpression(void);
    virtual ~BooleanExpression(void);

    virtual bool Evaluate(Context&) = 0;
	virtual char getType(){return 'Q';};
	virtual char getVar(){return '?';};
	
	virtual BooleanExpression* getOperand1(){return NULL;};
	virtual BooleanExpression* getOperand2(){return NULL;};
	virtual void setOperands(BooleanExpression*, BooleanExpression* = NULL){};
};
#endif

