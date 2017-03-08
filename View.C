#include "View.h"
#include <iostream>
#include <string>

using namespace std;

void View::tableRow(bool w,bool res)
{
	cout << "| " << w <<" || "<<res << "|" << endl;              
}


void View::getView(char op,char l,char r,int i,int iL,int iR,bool _not)
{
	string end = "       ";
	if (_not==false)
	{
		cout << "|       ";
		if (iL<0)
			cout << " " << l;
		else
			cout << "#"  << iL;
		cout << "    ";	
		if (iR<0)
			cout << " " << r;
		else
			cout << "#" << iR;
		cout <<"         "<<end<<"|"<<endl;
		cout << "|        |     |         "<<end<<"|"<<endl;
		cout << "|      +---------+       "<<end<<"|"<<endl;
		if (op=='A')
			cout << "|      |   AND   |       "<<end<<"|"<<endl;
		else if (op=='O')
			cout << "|      |   OR    |       "<<end<<"|"<<endl;
			
		else if (op=='$')
			cout << "|      |  NAND   |       "<<end<<"|"<<endl;
		else if (op=='=')
			cout << "|      |EQUIVALEN|       "<<end<<"|"<<endl;
		else if (op=='U')
			cout << "|      |   XOR   |       "<<end<<"|"<<endl;
		else if (op=='^')
			cout << "|      |   NOR   |       "<<end<<"|"<<endl;
		cout << "|      +---------+       "<<end<<"|"<<endl;
		cout << "|           |            "<<end<<"|"<<endl;
		if (i!=-1)
		{
			cout << "|          #"<<i<<"            "<<end<<"|"<<endl;
		} else
		{
			cout << "|         FINAL          "<<end<<"|"<<endl;
		}
		cout << "|                               |" << end << endl << "|                        "<<end<<"|"<<endl;
	} else 
	{
		cout << "|           ";
		if (op=='T')
			cout << "F";
		else cout << "T";
		cout <<"            "<<end<<"|"<<endl;
		cout << "|           |            "<<end<<"|"<<endl;
		cout << "|      +---------+       "<<end<<"|"<<endl;
		cout << "|      |   NOT   |       "<<end<<"|"<<endl;
		cout << "|      +----+----+       "<<end<<"|"<<endl;
		
		if (l=='R')
		{
			cout << "|              |         "<<end<<"|"<<endl;
		} else
		{
			cout << "|        |               "<<end<<"|"<<endl;
		}
		
		
	}
}

