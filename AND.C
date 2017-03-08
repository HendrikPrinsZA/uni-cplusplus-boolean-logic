#include <stdio.h>
#include "BooleanExpression.h"
#include "AND.h"

AndExpression::AndExpression(BooleanExpression* op1, BooleanExpression* op2)
{
    _operand1 = op1;
    _operand2 = op2;
}

AndExpression::~AndExpression(void)
{
	_operand1 = NULL;
	_operand2 = NULL;	
}

bool AndExpression::Evaluate(Context& aContext)
{
    bool oper1Eval = _operand1->Evaluate(aContext);
    bool oper2Eval = _operand2->Evaluate(aContext);
    ////HELPprintf("And expression parameters: %d %d\n", oper1Eval, oper2Eval);
    ////HELPprintf("And expression result: %d\n", oper1Eval && oper2Eval);
    return
        oper1Eval && oper2Eval;
}

