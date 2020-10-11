#pragma once
#ifndef INPUT_H
#define INPUT_H 
#include "pch.h"

class input :public base {
public:
	using base::base;
	vector<vector <char>> in();
};
#endif
