#pragma once
#ifndef CHECKBOTTOM_H
#define CHECKBOTTOM_H 
#include "pch.h"

class CheckBottom :public base {
public:
	using base::base;
	void p_signal_check_right(string &text);   
	void p_signal_go_bottom(string &text);      
	void p_hendler(string text);
};
#endif
