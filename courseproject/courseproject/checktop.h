#pragma once
#ifndef CHECKTOP_H
#define CHECKTOP_H 
#include "pch.h"

class CheckTop :public base {
public:
	using base::base;

	void p_signal_check_bottom(string &text);  
	void p_signal_go_top(string &text);     
	void p_hendler(string text);
};
#endif
