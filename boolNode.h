#include <iostream>
#include <string>

#include "Variable.h"
#include "BooleanExpression.h"
#include "OR.h"
#include "AND.h"
#include "NAND.h"
#include "EQUIV.h"
#include "NOT.h"
#include "XOR.h"
#include "NOR.h"
#include "Constant.h"
#include "Context.h"

class boolNode
{
	public:
		boolNode(char);
		boolNode(BooleanExpression*);
		
		~boolNode();
		
		void setFx(char);
		
		void setLeft(BooleanExpression*);
		void setRight(BooleanExpression*);
		
		
		bool result(Context&);
	//private:
		
		BooleanExpression* fx;
	
		boolNode* childLeft;
		boolNode* childRight;
};

