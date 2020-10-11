#pragma once
#ifndef ROOT_H
#define ROOT_H 
#include "pch.h"

struct Data
{
	int x;         
	int y;
	vector<vector<char>> field;
	string state;
};
class root :public base {
private:
	struct coordinates
	{
		int x;                
		int y;
	};
	Data data;
	static const string goTop;
	static const string goBottom;
	static const string goRight;
	static const string unknown;
	static const string delimeter;
public:
	static string getGoTop();
	static string getGoBottom();
	static string getGoRight();
	static string getUnknown();
	using base::base;
	void build_tree();
	void build_connections();
	void build();
	void p_signal_check_top(string & text);
	void p_hendler(string text);
	void exec();
	static string DataToString(Data data);       
	static Data StringToData(string str);
	root::coordinates findFirst(vector<vector<char>> field);
};
#define SIGNAL_D(T,signal_f)(TYPE_SIGNAL(&T::signal_f))
#define HENDLER_D(G,hendler_f)(TYPE_HANDLER(&G::hendler_f))
#endif
