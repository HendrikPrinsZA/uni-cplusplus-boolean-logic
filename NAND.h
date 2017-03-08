#ifndef NAND_H
#define NAND_H

class NandExpression : public BooleanExpression
{
public:
    explicit NandExpression(BooleanExpression*, BooleanExpression*);
    virtual ~NandExpression();

    virtual bool Evaluate(Context&);
	char getType(){return '$';};
	
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

