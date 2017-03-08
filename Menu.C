#include "Menu.h"

using namespace std;


Menu::Menu()
{
	input = NULL;
	EndScreen = 200;
	pre = false;
	iDisplay = 1;
}

void Menu::Main()
{
	int option = -1;
	for (int i=0; i<EndScreen; i++)
		cout << endl;
	while (option!=0)
	{
		cout << " ======================== " << endl;
		cout << "|        MAIN MENU       |" << endl;
		cout << "|                        |" << endl;
		cout << "|     Function           |" << endl;
		cout << "|1) Enter new function   |" << endl;
		cout << "|2) Display function     |" << endl;
		cout << "|3) Evaluate function    |" << endl;
		cout << "|                        |" << endl;
		cout << "|     Setup              |" << endl;
		cout << "|4) Set function display |" << endl;
		cout << "|5) Assign Variables     |" << endl;
		cout << "|                        |" << endl;
		cout << "|     Load/Save          |" << endl;
		cout << "|6) Store func to file   |" << endl;
		cout << "|7) Load func from file  |" << endl;
		cout << "|0) Exit                 |" << endl;
		cout << " ======================== " << endl;
		cout << "Option: ";
		cin >> option;
		SubMenu(option);
	}
	if (input!=NULL)
	{
		delete input;
		input = NULL;
	}
}

void Menu::SubMenu(int op)
{
	int option = -1;
	switch(op)
	{
		case 1:	
				while(option!=0)
				{
					for (int i=0; i<EndScreen; i++)
					cout << endl;
					cout << " ======================== " << endl;
					cout << "|1) ENTER NEW FUNCTION   |" << endl;
					cout << "|                        |" << endl;
					cout << "| Enter your function by |" << endl;
					cout << "| making use of the pre- |" << endl;
					cout << "| defined keywords       |" << endl;
					cout << "|                        |" << endl;
					cout << "| 1)Enter function       |" << endl;
					cout << "| 2)Toggle keywords      |" << endl;
					cout << "|                        |" << endl;
					cout << "| 0)Back To Main         |" << endl;
					cout << " ======================== " << endl;
					if (pre==true)
					{
						cout << "|         KEYWORDS       |" << endl;
						cout << "|                        |" << endl;
						cout << "|Keyword:         Type   |" << endl;
						cout << "|&&          :AND        |" << endl;
						cout << "|||          :OR         |" << endl;
						cout << "|!           :NOT        |" << endl;
						cout << "|$$          :NAND       |" << endl;
						cout << "|==          :EQUIVALENCE|" << endl;
						cout << "|UU          :XOR        |" << endl;
						cout << "|^^          :NOR        |" << endl;
						cout << "|T           :TRUE       |" << endl;
						cout << "|F           :FALSE      |" << endl;
						cout << "|X           :VARIABLE X |" << endl;
						cout << "|Y           :VARIABLE Y |" << endl;
						cout << "|()          :BRACKETS   |" << endl;
						cout << " ======================== " << endl;
					}
					cout << "Option: ";
					cin >> option;
					if (option==2)
					{
						if (pre==false)
							pre=true;
						else pre = false;
					} else if (option==1)
					{
						if (input!=NULL)
						{
							delete input;
							input = NULL;
						}
						input = new Input();
						input->getInput();
						break;
					} else if (option==0)
					{
						break;
					}
				}
			break;
		case 2:
			if (input!=NULL)
			{
				cout << " =============================== " << endl;
				cout << "|  3) DISPLAY FUNCTION          |" << endl;
				//cout << endl;
				input->Output(iDisplay);
				//input->Output(3);
				//cout << endl;
				cout << " =============================== " << endl;
			} else 
			{
				cout << " ======================== " << endl;
				cout << "|3) DISPLAY FUNCTION     |" << endl;
				cout << "|                        |" << endl;
				cout << "| No function found...   |" << endl;
				cout << " ======================== " << endl;
			}
			break;
		case 3:
			if (input!=NULL)
			{
				cout << " ======================== " << endl;
				cout << "|3) Evaluate function    |" << endl;
				cout << "|                        |" << endl;
				cout << "| Result = "<< input->Calculate() <<"             |" << endl;
				cout << " ======================== " << endl;
			} else
			{
				cout << " ======================== " << endl;
				cout << "|3) Evaluate function    |" << endl;
				cout << "|                        |" << endl;
				cout << "| No function found...   |" << endl;
				cout << " ======================== " << endl;
			}
			break;
		case 4:
				while(option!=0)
				{
					for (int i=0; i<EndScreen; i++)
					cout << endl;
					cout << " ======================== " << endl;
					cout << "|1) SET FUNCTION DISPLAY |" << endl;
					cout << "|                        |" << endl;
					cout << "| You can choose the way |" << endl;
					cout << "| in which you view your |" << endl;
					cout << "| function.              |" << endl;
					cout << "|                        |" << endl;
					cout << "| 1)Boolean algebra      |" << endl;
					cout << "| 2)Tree based           |" << endl;
					cout << "| 3)Truth table          |" << endl;
					cout << "|                        |" << endl;
					cout << "| 0)Back To Main         |" << endl;
					cout << " ======================== " << endl;
					cout << "Option: ";
					cin >> option;
					if (option == 1 || option == 2 || option == 3)
					{
						iDisplay = option;
						option = 0;
						//break;
					}
				}
				break;
		case 5:
			if (input==NULL)
			{
				cout << " ======================== " << endl;
				cout << "|1) ASSIGN VARIABLES     |" << endl;
				cout << "|                        |" << endl;
				cout << "| No function found...   |" << endl;
				cout << " ======================== " << endl;
			} else
			{
				while(option!=0)
				{
					for (int i=0; i<EndScreen; i++)
					cout << endl;
					cout << " ======================== " << endl;
					cout << "|1) ASSIGN VARIABLES     |" << endl;
					cout << "|                        |" << endl;
					cout << "| You can assign values  |" << endl;
					cout << "| to the variables you   |" << endl;
					cout << "| whish to use in your   |" << endl;
					cout << "| function.              |" << endl;
					cout << "|                        |" << endl;
					cout << "| 1)Assign all true      |" << endl;
					cout << "| 2)Assign all false     |" << endl;
					cout << "| 3)Assign W             |" << endl;
					cout << "| 4)Assign X             |" << endl;
					cout << "| 5)Assign Y             |" << endl;
					cout << "| 6)Assign Z             |" << endl;
					cout << "|                        |" << endl;
					cout << "| 0)Back To Main         |" << endl;
					cout << " ======================== " << endl;
					cout << "Option: ";
					cin >> option;
					int iBool = 0;
					if (option == 1)
					{
						input->assignAll(true);          
						break;
					} else if (option == 2)
					{
						input->assignAll(false);
						break;
					} else if (option == 3)
					{
						int iBool = 0;
						while(iBool!=1 && iBool!=2)
						{
							cout << " ======================== " << endl;
							cout << "|1.1) ASSIGN W           |" << endl;
							cout << "|                        |" << endl;
							cout << "| 1)True                 |" << endl;
							cout << "| 2)False                |" << endl;
							cout << " ======================== " << endl;
							cout << "Option: ";
							cin >> iBool;
						}
						if (iBool==1)
							input->assignV('W',true);
						else input->assignV('W',false);
						break;						
					} else if (option == 4)
					{
						int iBool = 0;
						while(iBool!=1 && iBool!=2)
						{
							cout << " ======================== " << endl;
							cout << "|1.1) ASSIGN X           |" << endl;
							cout << "|                        |" << endl;
							cout << "| 1)True                 |" << endl;
							cout << "| 2)False                |" << endl;
							cout << " ======================== " << endl;
							cout << "Option: ";
							cin >> iBool;
						}
						if (iBool==1)
							input->assignV('X',true);
						else input->assignV('X',false);
						break;						
					} else if (option == 5)
					{
						int iBool = 0;
						while(iBool!=1 && iBool!=2)
						{
							cout << " ======================== " << endl;
							cout << "|1.1) ASSIGN Y           |" << endl;
							cout << "|                        |" << endl;
							cout << "| 1)True                 |" << endl;
							cout << "| 2)False                |" << endl;
							cout << " ======================== " << endl;
							cout << "Option: ";
							cin >> iBool;
						}
						if (iBool==1)
							input->assignV('Y',true);
						else input->assignV('Y',false);
						break;						
					} else if (option == 6)
					{
						int iBool = 0;
						while(iBool!=1 && iBool!=2)
						{
							cout << " ======================== " << endl;
							cout << "|1.1) ASSIGN Z           |" << endl;
							cout << "|                        |" << endl;
							cout << "| 1)True                 |" << endl;
							cout << "| 2)False                |" << endl;
							cout << " ======================== " << endl;
							cout << "Option: ";
							cin >> iBool;
						}
						if (iBool==1)
							input->assignV('Z',true);
						else input->assignV('Z',false);
						break;						
					} 
				
				}
			}
			break;
			case 6:
			if (input!=NULL)
			{
					char tmp[20];
					cout << " ======================== " << endl;
					cout << "|6) STORE FUNC TO FILE   |" << endl;
					cout << "|                        |" << endl;
					cout << "| Please insert file     |" << endl;
					cout << "| name:                  |" << endl;
					cout << " ======================== " << endl;
					cout << "File name: ";
					cin >> tmp;
					
					outputFile.open(tmp);
					if (outputFile.fail())
						cout << "Error opening file" << endl;
					else
					{
						string sLyn = input->getFx();
						outputFile << sLyn;
					}
					outputFile.close();
			} else
			{
				cout << " ======================== " << endl;
				cout << "|6) STORE FUNC TO FILE   |" << endl;
				cout << "|                        |" << endl;
				cout << "| No function found...   |" << endl;
				cout << " ======================== " << endl;
			}
			
			break;
			case 7:
				if (input!=NULL)
				{
					delete input;
					input = NULL;
				}
				char tmp[20];
				cout << " ======================== " << endl;
				cout << "|7) Load func from file  |" << endl;
				cout << "|                        |" << endl;
				cout << "| Please insert file     |" << endl;
				cout << "| name:                  |" << endl;
				cout << " ======================== " << endl;
				cout << "File name: ";
				cin >> tmp;
				inputFile.open(tmp);
				if (inputFile.fail())
					cout << "Error opening file" << endl;
				else
				{
					//string sLyn = input->getFx();
					//outputFile << sLyn;
					char _fx[256];
					inputFile.getline(_fx,256);
					input = new Input();
					input->getInput(_fx);
					//cout << "TESTING: " << _fx << 'M' << endl;
				}
				inputFile.close();
				
			break;
			
		default:
			break;
	}
}



	/*Input *input = new Input();
	input->getInput();
	
	//char fxEQUIVALENCE[256] = "((X$$Y) || (!X&&!Y))%";
	input->getInput(fxEQUIVALENCE);
	
	bool result = input->Calculate();
	
	input->Output(2);

	delete input;*/
	
	

