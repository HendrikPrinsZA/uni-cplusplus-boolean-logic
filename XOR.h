#ifndef XOR_H
#define XOR_H

class XorExpression : public BooleanExpression
{
public:
    explicit XorExpression(BooleanExpression*, BooleanExpression*);
    virtual ~XorExpression();

    virtual bool Evaluate(Context&);
	char getType(){return 'U';};
	
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

