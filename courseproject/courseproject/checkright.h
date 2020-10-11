#pragma once
#ifndef CHECKRIGHT_H
#define CHECKRIGHT_H 
#include "pch.h"

class CheckRight :public base {
public:
	using base::base;

	void p_signal_end(string &text);         
	void p_signal_go_right(string &text);         
	void p_hendler(string text);
};
#endif
