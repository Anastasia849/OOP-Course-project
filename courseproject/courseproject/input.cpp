#include "pch.h"

#include <iostream> 
using namespace std;

vector<vector <char>> input::in()
{
	vector<vector <char>> field;        
	for (int i = 0; i < 10; i++)
	{
		vector <char> v;               
		field.push_back(v);                
		for (int j = 0; j < 10; j++)
		{
			char k;                        
			cin >> k;                        
			field[i].push_back(k);
		}
	}         return field;
}
