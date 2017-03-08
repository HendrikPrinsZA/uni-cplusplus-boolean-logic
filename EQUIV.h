#ifndef EQUIV_H
#define EQUIV_H

class EquivExpression : public BooleanExpression
{
public:
    explicit EquivExpression(BooleanExpression*, BooleanExpression*);
    virtual ~EquivExpression();

    virtual bool Evaluate(Context&);
	char getType(){return '=';};
	
	BooleanExpression* getOperand1(){return _operand1;};
	BooleanExpression* getOperand2(){return _operand2;};
	
	void setOperands(BooleanExpression* op1, BooleanExpression* op2)
	{
		_operand1 = op1;
		_operand2 = op2;
	};

private:
    BooleanExpression* _operand1;
    BooleanExpression* _operand2;
};
#endif

