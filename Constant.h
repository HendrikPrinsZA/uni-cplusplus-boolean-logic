 #ifndef CONSTANT_H
#define CONSTANT_H

#include "BooleanExpression.h"

class Constant : public BooleanExpression
{
public:
    explicit Constant(bool);
    virtual ~Constant();

    virtual bool Evaluate(Context&);
	char getType(){return 'C';};
	
private:
    bool _operand1;
};
#endif
