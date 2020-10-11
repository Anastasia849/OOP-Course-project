#include "pch.h"

#include <iostream>
using namespace std;
void output::out(vector<vector <char>> field)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)  
			cout << field[i][j];    
		if (i != 9)cout << "\n";
	}
}
