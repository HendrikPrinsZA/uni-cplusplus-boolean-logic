#ifndef OREXPRESSION_H
#define OREXPRESSION_H

class OrExpression : public BooleanExpression
{
public:
    explicit OrExpression(BooleanExpression*, BooleanExpression*);
    virtual ~OrExpression();

    virtual bool Evaluate(Context&);
	char getType(){return 'O';};

private:
    BooleanExpression* _operand1;
    BooleanExpression* _operand2;
};
#endif

