#pragma once
#ifndef DOSTEP_H
#define DOSTEP_H
#include "pch.h"

class DoStep:public base {
public:   
	using base::base;      
	void p_hendler(string text);
	void p_signal(string& text);
};
#endif

