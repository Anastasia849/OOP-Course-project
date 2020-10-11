#include "pch.h"


void CheckRight::p_signal_end(string &text)
{
	Data data = root::StringToData(text);   
	data.state = root::getUnknown();       
	text = root::DataToString(data);
}
void CheckRight::p_signal_go_right(string &text)
{
	Data data = root::StringToData(text);   
	data.state = root::getGoRight();      
	text = root::DataToString(data);
}
void CheckRight::p_hendler(string text)
{
	Data data = root::StringToData(text);
	if (data.x + 1 < 10 && data.field[data.y][data.x + 1] == '1')       
		emitSignal(SIGNAL_D(CheckRight, p_signal_go_right), text);      
	else emitSignal(SIGNAL_D(CheckRight, p_signal_end), text);
}
