#include "Input.h"
//#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <cctype>


void Input::Output(int i)
{
	char op,l,r;
	int iL,iR;
	bool _not;
	//HELPcout << endl << endl << endl << "================= STARTING OUTPUT ============" << endl;
	if (i==1)//boolean algebra
	{
		cout << "|                               |" << endl;
		cout << "|  Boolean algebra              |" << endl;
		cout << "| ";
		int counter = 29;
		for (int a=0; a<sFunction.length(); a++)
		{
			//counter--;
			cout << sFunction[a];
			counter--;
			if (counter==0)
			{
				cout << " |" << endl <<"| ";
				counter = 29;
			}
		}
		for (int a=0; a<counter; a++)
		{
			cout << " ";
		}
		cout << " |" << endl;
	} else if (i==2)
	{
		for (int a=0; a<fxList.size(); a++)
		{
			op = '?';
			l = '?';
			r = '?';
			iL = -1;
			iR = -1;
			_not = false;
			if (fxList[a]!=NULL)
			{
				//checked if exists
				if (fxList[a]->fx!=NULL)
				{
					op = fxList[a]->fx->getType();
				}
				if (fxList[a]->childLeft!=NULL)
				{
					//Has child
					if (fxList[a]->childLeft->fx!=NULL)
					{
						//Child has fx
						if (fxList[a]->childLeft->fx->getType()=='C')
						{
							//Child has fx
							if (fxList[a]->childLeft->fx->Evaluate(context)==true)
								l = 'T';
							else l = 'F';
						} else if (fxList[a]->childLeft->fx->getType()=='V')
						{
							//Child has fx
							l= fxList[a]->childLeft->fx->getVar();
						} else if (fxList[a]->childLeft->fx->getType()=='N')///NOT
						{
							if (fxList[a]->childLeft->fx->Evaluate(context)==true)
								l = 'T';
							else l = 'F';	
							_not = true;
							myView.getView(r,'L','?',a,0,0,_not);
						} else
						{
							iL = a-1;
						}
					}
				}
				if (fxList[a]->childRight!=NULL)
				{
					//Has child
					if (fxList[a]->childRight->fx!=NULL)
					{
						//Child has fx
						if (fxList[a]->childRight->fx->getType()=='C')
						{
							if (fxList[a]->childRight->fx->Evaluate(context)==true)
								r = 'T';
							else r = 'F';
						} else if (fxList[a]->childRight->fx->getType()=='V')
						{
							r= fxList[a]->childRight->fx->getVar();
						} else if (fxList[a]->childRight->fx->getType()=='N')///NOT
						{
							if (fxList[a]->childRight->fx->Evaluate(context)==true)
								r = 'T';
							else r = 'F';	
							_not = true;
							myView.getView(r,'R','?',a,0,0,_not);
						} else
						{
							if (iL>-1)
								iR = a-2;
							else iR = a-1;
						}
					}
				}
			}
			if (a==fxList.size()-1)
				myView.getView(op,l,r,-1,iL,iR);
			else myView.getView(op,l,r,a,iL,iR);
		}
	} else if (i==3)
	{
		string add = "|  ";
		string end = "  |"; 
		bool tempW,tempX,tempY,tempZ;
		bool _w,_x,_y,_z;
		_w = false;
		_x = false;
		_y = false;
		_z = false;
		tempW = w->Evaluate(context);
		tempX = x->Evaluate(context);
		tempY = y->Evaluate(context);
		tempZ = z->Evaluate(context);
		
		double nmrOfVar = 0;
		double nmr = 0;
		
		//cout << "Searching in " << sFunction << endl;
		
		//cout << sFunction.find('X',1) << " bool:" << (sFunction.find('X',0)) << endl;
		
		for (int _a = 0; _a<sFunction.length(); _a++)
		{
			if (sFunction[_a]=='W')
			{
				_w = true;
			} else if (sFunction[_a]=='X')
			{
				_x = true;
			} else if (sFunction[_a]=='Y')
			{
				_y = true;
			} else if (sFunction[_a]=='Z')
			{
				_z = true;
			}
		}
		if (_w==true)
			nmrOfVar++;
		if (_x==true)
			nmrOfVar++;
		if (_y==true)
			nmrOfVar++;
		if (_z==true)
			nmrOfVar++;
		cout << add;
		for (int a=0; a<nmrOfVar; a++)
		{
			cout << "+---";
		}
		cout << "++--------+" << end << endl << add <<"|";
		
		if (_w==true)
			cout << " w |";
		if (_x==true)
			cout << " x |";
		if (_y==true)
			cout << " y |";
		if (_z==true)
			cout << " z |";
		cout << "| Result |" << end << endl << add;
		
		for (int a=0; a<nmrOfVar; a++)
		{
			cout << "+---";
		}
		cout << "++--------+" << end << endl;
		
		nmr = nmrOfVar;
		nmrOfVar = pow(2.0,nmrOfVar);
		//cout << "Number of rows: " << nmrOfVar << endl;
		
		bool a1,a2,a3,a4;
		a1 = true;
		a2 = true;
		a3 = true;
		a4 = true;
		if ((_w==true)&&(_x==true)&&(_y==true)&&(_z==true))
		{
			for (int a=0; a<nmrOfVar; a++)
			{
				if ((a%1)==0)
				{
					if (a1==false)
						a1 = true;
					else a1 = false;
				}
				if ((a%2)==0)
				{
					if (a2==false)
						a2 = true;
					else a2 = false;
				}
				if ((a%4)==0)
				{
					if (a3==false)
						a3 = true;
					else a3 = false;
				}
				if ((a%8)==0)
				{
					if (a4==false)
						a4 = true;
					else a4 = false;
				}
				cout << add << "|" << " "<<a4<<" |"<< " "<<a3<<" |"<< " "<<a2<<" |"<< " "<<a1<<" |";
				assignV('W',a1);
				assignV('X',a2);
				assignV('Y',a3);
				assignV('Z',a4);
				cout <<"|   ";
				//Output result here
				cout << Calculate();
				cout <<"    |";
				cout << end << endl;
			}
		} else if ((_w==true)&&(_x==true)&&(_y==true))
		{
			for (int a=0; a<nmrOfVar; a++)
			{
				if ((a%1)==0)
				{
					if (a1==false)
						a1 = true;
					else a1 = false;
				}
				if ((a%2)==0)
				{
					if (a2==false)
						a2 = true;
					else a2 = false;
				}
				if ((a%4)==0)
				{
					if (a3==false)
						a3 = true;
					else a3 = false;
				}
				cout << add << "|" << " "<<a3<<" |"<< " "<<a2<<" |"<< " "<<a1<<" |";
				assignV('W',a1);
				assignV('X',a2);
				assignV('Y',a3);
				cout <<"|   ";
				//Output result here
				cout << Calculate();
				cout <<"    |";
				cout << end << endl;
			}
		} else if ((_w==true)&&(_x==true))
		{
			for (int a=0; a<nmrOfVar; a++)
			{
				if ((a%1)==0)
				{
					if (a1==false)
						a1 = true;
					else a1 = false;
				}
				if ((a%2)==0)
				{
					if (a2==false)
						a2 = true;
					else a2 = false;
				}
				cout << add << "|" << " "<<a2<<" |"<< " "<<a1<<" |";
				assignV('W',a1);
				assignV('X',a2);
				cout <<"|   ";
				//Output result here
				cout << Calculate();
				cout <<"    |";
				cout << end << endl;
			}
		} else if (_w==true)
		{
			for (int a=0; a<nmrOfVar; a++)
			{
				if ((a%1)==0)
				{
					if (a1==false)
						a1 = true;
					else a1 = false;
				}
				cout << add << "|" << " "<<a1<<" |";
				cout <<"|   ";
				//Output result here
				assignV('W',a1);
				cout <<  Calculate();
				cout <<"    |";
				cout << end << endl;
			}
		}
		cout << add;
		for (int a=0; a<nmr; a++)
		{
			cout << "+---";
		}
		cout << "++--------+" << end << endl;
	}
	//HELPcout << "=================  END OF OUTPUT  ============" << endl;
}

bool Input::Calculate()
{
	bool variables = false;
	char _x = 'A';
	char _y ='A';
	/*for (int a=0; a<fxList.size(); a++)
	{
		///////ERROR CHECKING NEEDED FOR CHILDREN
		if ((fxList[a]->childLeft->fx->getType()=='V')||(fxList[a]->childRight->fx->getType()=='V'))
			variables = true;
		//HELPcout <<"Operator " << a << " = " <<fxList[a]->childLeft->fx->getType() << endl;
	}*/
	
	/*if (variables==true)
	{
		cout << "Variables in function" << endl;
		cout << "Please enter the values...(T/F)" << endl;
		cout << "X = ";
		cin >>  _x;
		cout << "Y = ";
		cin >>  _y;
		
		while((_x!='T' && _x!='F') || (_y!='T' && _y!='F'))
		{
			cout << "Please re-enter the values...(T/F)" << endl;
			cout << "X = ";
			cin >>  _x;
			cout << "Y = ";
			cin >>  _y;
		}
		
		if (_x=='T')
			context.AssignX(x, true);
		else context.AssignX(x, false);
		if (_y=='T')
			context.AssignY(y, true);
		else context.AssignY(y, false);
	}*/
	return fxList[listPos]->result(context);
}


void Input::constructTree()
{
	//HELPcout << "CheckStart" << endl;
	int b = 0;
	b = sFunction.find(' ',0);
	while(b>-1)
	{
		sFunction.erase(b,1);
		b = sFunction.find(' ',0);
	}
	getLast(sFunction);
	//HELPcout << endl << endl << endl << "Answer:" << endl;
	
	/*/HELPcout << "head type:" << fxList[listPos]->fx->getType() << endl;
	for (int a=listPos-1; a>-1; a--)
	{
		cout << "listPos: " << a << ", funcType: " << fxList[a]->fx->getType() << endl;
	}*/
}

BooleanExpression* Input::getVariable(string s)
{
	BooleanExpression *temp;
	//-----HELP---cout << "Got variable: " << s << endl;
	if (s.length()==2)
	{
		if (s[1]=='F')
			temp = new Constant(false);
		else if (s[1]=='T')
			temp = new Constant(true);
		else if (s[1]=='X')
			temp = x;
		else if (s[1]=='Y')
			temp = y;	
		else if (s[1]=='W')
			temp = w;	
		else if (s[1]=='Z')
			temp = z;	
		return new NotExpression(temp);
	} else
	{
		if (s[0]=='F')
			return new Constant(false);
		else if (s[0]=='T')
			return new Constant(true);
		else if (s[0]=='X')
			return x;
		else if (s[0]=='Y')
			return y;
		else if (s[0]=='W')
			return w;
		else if (s[0]=='Z')
			return z;
		else if (isdigit(s[0]))
		{
			int i;
			char a[1];
			a[0]= s[0];
			i = atoi (a);
			return fxList[i]->fx;
		}
	}
	temp = NULL;
}


void Input::getFunction(string fx)
{
	//HELPcout << "getting inner function: " << fx << endl;
	for (int a=0; a<fx.length()-1; a++)
	{
		if ((fx.substr(a,2)=="!&")||(fx.substr(a,2)=="!|"))
		{
			getFunction(fx.erase(a,1)); //Erase not before operand to remove error
		}
	}
	
	for (int a=0; a<fx.length()-1; a++)
	{
		if (fx.substr(a,2)=="&&")
		{
			//HELPcout << "AND created" << endl;
			fxList.push_back(new boolNode('A'));
			listPos++;
			fxList[listPos]->setLeft(getVariable(fx.substr(0,a)));
			fxList[listPos]->setRight(getVariable(fx.substr(a+2,fx.length())));
			fxList[listPos]->setFx('A');
		} 
	}
		
	for (int a=0; a<fx.length()-1; a++)
	{	
		if (fx.substr(a,2)=="||")
		{
			//HELPcout << "OR created..." << endl;
			fxList.push_back(new boolNode('O'));
			listPos++;
			fxList[listPos]->setLeft(getVariable(fx.substr(0,a)));
			fxList[listPos]->setRight(getVariable(fx.substr(a+2,fx.length())));
			fxList[listPos]->setFx('O');
			//HELPcout << "OR created" << endl;
		}
	}
	for (int a=0; a<fx.length()-1; a++)
	{
		if (fx.substr(a,2)=="$$")
		{
			//HELPcout << "NAND created" << endl;
			fxList.push_back(new boolNode('$'));
			listPos++;
			fxList[listPos]->setLeft(getVariable(fx.substr(0,a)));
			fxList[listPos]->setRight(getVariable(fx.substr(a+2,fx.length())));
			fxList[listPos]->setFx('$');
		}
	}
	for (int a=0; a<fx.length()-1; a++)
	{
		if (fx.substr(a,2)=="==")
		{
			//HELPcout << "EQUIV created" << endl;
			fxList.push_back(new boolNode('='));
			listPos++;
			fxList[listPos]->setLeft(getVariable(fx.substr(0,a)));
			fxList[listPos]->setRight(getVariable(fx.substr(a+2,fx.length())));
			fxList[listPos]->setFx('=');
		}
	}
	for (int a=0; a<fx.length()-1; a++)
	{
		if (fx.substr(a,2)=="UU")
		{
			//HELPcout << "XOR created" << endl;
			fxList.push_back(new boolNode('U'));
			listPos++;
			fxList[listPos]->setLeft(getVariable(fx.substr(0,a)));
			fxList[listPos]->setRight(getVariable(fx.substr(a+2,fx.length())));
			fxList[listPos]->setFx('U');
		}
	}
	for (int a=0; a<fx.length()-1; a++)
	{
		if (fx.substr(a,2)=="^^")
		{
			//HELPcout << "NOR created" << endl;
			fxList.push_back(new boolNode('^'));
			listPos++;
			fxList[listPos]->setLeft(getVariable(fx.substr(0,a)));
			fxList[listPos]->setRight(getVariable(fx.substr(a+2,fx.length())));
			fxList[listPos]->setFx('^');
		}
	}
}

void Input::getLast(string fx,int last)
{
//+++++++++Start getting the deepest function+++++++
	int open = 0;
	int deepest = 0;
	int countDeepest = 0;
	if (last==0)
	{
		open = 0;
		deepest = 0;
		countDeepest = 0;
		for (int a=0; a<fx.length(); a++)
		{
			if (fx[a]=='(')
			{
				open++;	
			} else if (fx[a]==')')
				open--;
			if (fx[a]=='(')
				if (open>deepest)
				{
					deepest = open;
				}
		}
		for (int a=0; a<fx.length(); a++)
		{
			if (fx[a]=='(')
			{
				open++;	
				if (open==deepest)
					countDeepest++;
			} else if (fx[a]==')')
				open--;
		}
	} else
		deepest = last;
//--------------------------------------------------	
	
	open=0;
	for (int a=0; a<fx.length(); a++)
	{
		if (fx[a]=='(')
			open++;
	}
	if (open>0)
	{
		open = 0;
		int x = 0;
		int y = 0;
		for (int a=0; a<fx.length(); a++)
		{
			if (fx[a]=='(')
				open++;
			else if (fx[a]==')')
				open--;
			
			if (open==deepest && fx[a]=='(')
			{
				x = a+1;
			} else if (open==deepest-1 && fx[a]==')')
			{
				char buf[5];
				y = a-x;
				getFunction(fx.substr(x,y));
				fx.erase(x-1,y+2);
				itoa(listPos, buf, 10);//convert nmr to string [buf]
				fx.insert(x-1,buf);
				//HELPcout << "========================================= new fx= " << fx << endl;
			}
		}
		getLast(fx,(deepest-1));
	} else 
	{
		getFunction(fx.substr(0,fx.length()));
	}
}

void Input::assignV(char _c,bool _v)
{
	if (_c=='W')
		context.AssignW(w, _v);
	else if (_c=='X')
		context.AssignX(x, _v);
	else if (_c=='Y')
		context.AssignY(y, _v);
	else if (_c=='Z')
		context.AssignZ(z, _v);
		
}

void Input::assignAll(bool _v)
{
	context.AssignW(w, _v);
	context.AssignX(x, _v);
	context.AssignY(y, _v);
	context.AssignZ(z, _v);	
}


Input::Input()
{	
	w = new VariableExpression("W");
	x = new VariableExpression("X");
    y = new VariableExpression("Y");
	z = new VariableExpression("Z");
	
    context.AssignW(w, false);
	context.AssignX(x, false);
    context.AssignY(y, false);
	context.AssignZ(z, false);
   
	
	sValid[0] = "&&";//AND
	sValid[1] = "||";//OR
	sValid[2] = "X";//VARIABLE X
	sValid[3] = "Y";//VARIABLE Y
	sValid[4] = "(";
	sValid[5] = ")";
	sValid[6] = "!";//NOT
	sValid[7] = "T";//CONSTANT TRUE
	sValid[8] = "F";//CONSTANT FALSE
	sValid[9] = "$$";//NAND
	sValid[10] = "==";//EQUIV
	sValid[11] = "UU";//XOR
	sValid[12] = "^^";//NOR
	sValid[13] = "W";//VARIABLE W
	sValid[14] = "Z";//VARIABLE Z
	nmr = 15;
	
	fxList.clear();
	listPos = -1;
}

Input::~Input()
{	
	delete fxList[fxList.size()-1];
	for (int a=0; a<fxList.size(); a++)
	{
		fxList[a] = NULL;
	}
	fxList.clear();

	
	/*delete w;
	cout << "DELETED W" << endl;
	delete x;
	cout << "DELETED X" << endl;
	delete y;
	cout << "DELETED Y" << endl;
	delete z;
	cout << "DELETED Z" << endl;*/
	
	w = NULL;
	x = NULL;
	y = NULL;
	z = NULL;
	
	delete sValid;
}

void Input::getInput()
{
	char sInput[256];
	cout << "Enter function: ";
	cin.getline(sInput,256);
	sFunction = sInput;
	while (validateInput()==false)
	{
		cout << "!== Invalid function please try again ==!" << endl;
		cout << "Enter function: ";
		cin.getline(sInput,256);
		sFunction = sInput;
	}
	constructTree();
}

void Input::getInput(char sLyn[256])
{
	char sInput[256] = "";
	cout << "Function Loaded: ";
	cout << sLyn << endl;
	int a = 0;
	while(sLyn[a]!='\n')
	{
		sInput[a] = sLyn[a];
		a++;
	}
	cout << sInput << endl;
	sFunction = sInput;
	if (validateInput()==false)
	{
		getInput();
	}
	constructTree();
}

bool Input::validateInput()
{
	//+++++++++Start check string length++++++++++++++++
	if (sFunction.length()<2)
	{
		return false;
	}
	//--------------------------------------------------
	
	//+++++++++Start check brackets+++++++++++++++++++++
	int open = 0;
	for (int a=0; a<sFunction.length(); a++)
	{
		if (sFunction[a]=='(')
			open++;
		if (sFunction[a]==')')
			open--;
		if (open<0)
			return false;
	}
	if (open!=0)
		return false;
	//--------------------------------------------------	
	//+++++++++Call function to check keywords++++++++++
	return checkKeywords(sFunction);
	//--------------------------------------------------
	
	//+Make sure theres no operators next to eachother++
	return checkKeywords(sFunction);
	//--------------------------------------------------
	return true;
}

//+++++++++Start check keywords+++++++++++++++++++++
bool Input::checkKeywords(string check)
{
	int b = 0;
	b = check.find(' ',0);
	while(b>-1)
	{
		check.erase(b,1);
		b = check.find(' ',0);
	}
	for (int a=0; a<nmr; a++)
	{
		int b = 0;
		b = check.find(sValid[a],0);
		while(b>-1)
		{
			check.erase(b,sValid[a].length());
			b = check.find(sValid[a],0);
		}
	}
	if (check.length()>0)
	{
		cout <<"!==ERROR statement '"<< check << "' not expected in function==!" << endl;
		return false;
	}
	return true;
}

string Input::getFx()
{
	return sFunction;
}
//--------------------------------------------------

