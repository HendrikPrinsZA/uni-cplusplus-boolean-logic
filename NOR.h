#ifndef NOR_H
#define NOR_H

class NorExpression : public BooleanExpression
{
public:
    explicit NorExpression(BooleanExpression*, BooleanExpression*);
    virtual ~NorExpression();

    virtual bool Evaluate(Context&);
	char getType(){return '^';};
	
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

