#ifndef NOTEXPRESSION_H
#define NOTEXPRESSION_H

class NotExpression : public BooleanExpression
{
public:
    explicit NotExpression(BooleanExpression*);
    virtual ~NotExpression();

    virtual bool Evaluate(Context&);
	char getType(){return 'N';};

private:
    BooleanExpression* _operand1;
};
#endif

