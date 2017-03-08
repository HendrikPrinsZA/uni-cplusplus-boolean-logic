#include <stdio.h>
#include "BooleanExpression.h"
#include "EQUIV.h"

EquivExpression::EquivExpression(BooleanExpression* op1, BooleanExpression* op2)
{
    _operand1 = op1;
    _operand2 = op2;
}

EquivExpression::~EquivExpression(void)
{
}

bool EquivExpression::Evaluate(Context& aContext)
{
    bool oper1Eval = _operand1->Evaluate(aContext);
    bool oper2Eval = _operand2->Evaluate(aContext);

    //HELPprintf("Equiv expression parameters: %d %d\n", oper1Eval, oper2Eval);
    //HELPprintf("Equiv expression result: %d\n", ((!oper1Eval && !oper2Eval) || (oper1Eval && oper2Eval)));

    return
		((!oper1Eval && !oper2Eval) || (oper1Eval && oper2Eval));
}

