#include "pch.h"

void DoStep::p_hendler(string text)
{
	Data data = root::StringToData(text);     
	data.field[data.y][data.x] = 'F';         
	if (data.state == root::getGoTop())data.y--;   
	else if (data.state == root::getGoBottom())data.y++;   
	else if (data.state == root::getGoRight())data.x++;
	text = root::DataToString(data);
	emitSignal(SIGNAL_D(DoStep, p_signal), text);
}

void DoStep::p_signal(string & text){}
