#include "Constant.h"

Constant::Constant(bool op1)
{
    _operand1 = op1;
}

bool Constant::Evaluate(Context& aContext)
{
    return (_operand1);
}

Constant::~Constant(void)
{
}

