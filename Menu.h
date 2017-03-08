#include <iostream>
#include "Input.h"
#include <fstream>

using namespace std;

class Menu
{
	public:
		Menu();
		void Main();
		void SubMenu(int);
		
	private:
		int EndScreen;
		int iDisplay;
		Input *input;
		bool pre;
		ofstream outputFile;
		ifstream inputFile;
};

