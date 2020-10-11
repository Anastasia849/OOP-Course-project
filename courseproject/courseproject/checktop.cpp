#include "pch.h"



void CheckTop::p_signal_check_bottom(string &text) {} 
void CheckTop::p_signal_go_top(string &text)
{
	Data data = root::StringToData(text);   
	data.state = root::getGoTop();        
	text = root::DataToString(data);
}
void CheckTop::p_hendler(string text)
{
	Data data = root::StringToData(text);       
	if (data.y > 0 && data.field[data.y - 1][data.x] == '1')           
		emitSignal(SIGNAL_D(CheckTop, p_signal_go_top), text);      
	else emitSignal(SIGNAL_D(CheckTop, p_signal_check_bottom), text);
}
