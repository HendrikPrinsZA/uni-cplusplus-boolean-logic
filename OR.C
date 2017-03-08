#include <stdio.h>

#include "BooleanExpression.h"
#include "Context.h"
#include "OR.h"

class Context;

OrExpression::OrExpression(BooleanExpression* op1, BooleanExpression* op2)
{
    _operand1 = op1;
    _operand2 = op2;
}

bool OrExpression::Evaluate(Context& aContext)
{
    bool oper1Eval = _operand1->Evaluate(aContext);
    bool oper2Eval = _operand2->Evaluate(aContext);

    //HELPprintf("Or expression parameters: %d %d\n", oper1Eval, oper2Eval);
    //HELPprintf("Or expression result: %d\n", oper1Eval || oper2Eval);

    return
        oper1Eval || oper2Eval;
}

OrExpression::~OrExpression(void)
{
}

