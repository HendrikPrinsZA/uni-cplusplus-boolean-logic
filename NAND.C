#include <stdio.h>
#include "BooleanExpression.h"
#include "NAND.h"

NandExpression::NandExpression(BooleanExpression* op1, BooleanExpression* op2)
{
    _operand1 = op1;
    _operand2 = op2;
}

NandExpression::~NandExpression(void)
{
}

bool NandExpression::Evaluate(Context& aContext)
{
    bool oper1Eval = _operand1->Evaluate(aContext);
    bool oper2Eval = _operand2->Evaluate(aContext);

    //HELPprintf("Nand expression parameters: %d %d\n", oper1Eval, oper2Eval);
    //HELPprintf("Nand expression result: %d\n", !(oper1Eval && oper2Eval));

    return
        !(oper1Eval && oper2Eval);
}

