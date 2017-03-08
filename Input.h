#include <iostream>
#include <string>
#include <vector>

#include "View.h"
#include "boolNode.h"

using namespace std;

class Input
{
	public:
		Input();
		~Input();
		
		void Output(int);
		bool Calculate();

		void getInput();
		void getInput(char*);
		string getFx();
		bool validateInput();
		bool checkKeywords(string);
		
		void constructTree();
		void getLast(string, int last=0);
		void getFunction(string);
		
		void assignV(char,bool);
		void assignAll(bool);
		
		BooleanExpression* getVariable(string);
	
	protected:
		vector<boolNode*> fxList;
		int listPos;
		
		Context context;
		VariableExpression* w;
		VariableExpression* x;
		VariableExpression* y;
		VariableExpression* z;
		
		
		string sFunction;
		
		string sValid[15];
		int nmr; //13
		View myView;
		
		
};

