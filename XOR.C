#include <stdio.h>
#include "BooleanExpression.h"
#include "XOR.h"

XorExpression::XorExpression(BooleanExpression* op1, BooleanExpression* op2)
{
    _operand1 = op1;
    _operand2 = op2;
}

XorExpression::~XorExpression(void)
{
}

bool XorExpression::Evaluate(Context& aContext)
{
    bool oper1Eval = _operand1->Evaluate(aContext);
    bool oper2Eval = _operand2->Evaluate(aContext);

    //HELPprintf("Xor expression parameters: %d %d\n", oper1Eval, oper2Eval);
    //HELPprintf("Xor expression result: %d\n", !((!oper1Eval && !oper2Eval) || (oper1Eval && oper2Eval)));

    return
		!((!oper1Eval && !oper2Eval) || (oper1Eval && oper2Eval));
}

