#include "boolNode.h"
#include <iostream>
using namespace std;


boolNode::boolNode(BooleanExpression *_fx)
{
	fx = _fx;
	childLeft = NULL;
	childRight = NULL;
}

boolNode::~boolNode()
{
	if (childLeft!=NULL)
	{
		delete childLeft;
		childLeft = NULL;
	}
	if (childRight!=NULL)
	{
		delete childRight;
		childRight = NULL;
	}
	if (fx!=NULL)
	{
		//HELPcout << fx->getType() << " : Deleted" << endl;
		delete fx;
		fx = NULL;
	}
}

boolNode::boolNode(char _fx)
{
	if (_fx=='A')
	{
		fx = new AndExpression(NULL,NULL);
	} else if (_fx=='O')
	{
		fx = new OrExpression(NULL,NULL);
	} else if (_fx=='!')
	{
		fx = new NotExpression(NULL);
	} if (_fx=='$')
	{
		fx = new NandExpression(NULL,NULL);
	} else if (_fx=='=')
	{
		fx = new NandExpression(NULL,NULL);
	} else if (_fx=='U')
	{
		fx = new XorExpression(NULL,NULL);
	} else if (_fx=='^')
	{
		fx = new NorExpression(NULL,NULL);
	} 
	
}

void boolNode::setFx(char _fx)
{
	if (_fx=='A')
	{
		fx = new AndExpression(childLeft->fx,childRight->fx);
	} else if (_fx=='O')
	{
		fx = new OrExpression(childLeft->fx,childRight->fx);
	} else if (_fx=='!')
	{
		fx = new NotExpression(childLeft->fx);
	} else if (_fx=='$')
	{
		fx = new NandExpression(childLeft->fx,childRight->fx);
	} else if (_fx=='=')
	{
		fx = new EquivExpression(childLeft->fx,childRight->fx);
	} else if (_fx=='U')
	{
		fx = new XorExpression(childLeft->fx,childRight->fx);
	} else if (_fx=='^')
	{
		fx = new NorExpression(childLeft->fx,childRight->fx);
	}
}

void boolNode::setLeft(BooleanExpression* left)
{
	childLeft = new boolNode(left);
}

void boolNode::setRight(BooleanExpression* right)
{
	childRight = new boolNode(right);
}

bool boolNode::result(Context& context)
{
	return fx->Evaluate(context);
}


