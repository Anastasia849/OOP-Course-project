// courseproject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <string>
#include <iostream> 

using namespace std;
int main()
{
	root r(NULL);
	r.build();
	r.exec();         
	return(0);
}
