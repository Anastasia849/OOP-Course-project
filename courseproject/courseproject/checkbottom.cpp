#include "pch.h"

void CheckBottom::p_signal_check_right(string &text) {}
void CheckBottom::p_signal_go_bottom(string &text)
{
	Data data = root::StringToData(text);      
	data.state = root::getGoBottom();    
	text = root::DataToString(data);
}
void CheckBottom::p_hendler(string text)
{
	Data data = root::StringToData(text);
	if (data.y + 1 < 10 && data.field[data.y + 1][data.x] == '1')
		emitSignal(SIGNAL_D(CheckBottom, p_signal_go_bottom), text);      
	else emitSignal(SIGNAL_D(CheckBottom, p_signal_check_right), text);
}
