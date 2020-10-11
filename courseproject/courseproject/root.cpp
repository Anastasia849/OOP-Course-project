#include "pch.h"

#include <iostream> 
using namespace std;
void root::build_tree()
{
	setName("root");

	input in = new input(this, "in");
	CheckRight checkRight = new CheckRight(this, "checkRight");
	CheckTop checkTop = new CheckTop(this, "checkTop");
	CheckBottom checkBottom = new CheckBottom(this, "checkBottom");
	output out = new output(this, "out");
	DoStep doStep = new DoStep(this, "doStep");
}
void root::build_connections()
{
	base* checkTop = find("checkTop");
	base* checkRight = find("checkRight");
	base* checkBottom = find("checkBottom");
	base* doStep = find("doStep");

	this->setConnect(SIGNAL_D(root, p_signal_check_top), checkTop, HENDLER_D(CheckTop, p_hendler));
	checkTop->setConnect(SIGNAL_D(CheckTop, p_signal_check_bottom), checkBottom, HENDLER_D(CheckBottom, p_hendler));
	checkTop->setConnect(SIGNAL_D(CheckTop, p_signal_go_top), doStep, HENDLER_D(DoStep, p_hendler));
	checkBottom->setConnect(SIGNAL_D(CheckBottom, p_signal_check_right), checkRight,HENDLER_D(CheckRight, p_hendler));
	checkBottom->setConnect(SIGNAL_D(CheckBottom, p_signal_go_bottom), doStep, HENDLER_D(DoStep, p_hendler));
	checkRight->setConnect(SIGNAL_D(CheckRight, p_signal_end), doStep, HENDLER_D(DoStep, p_hendler));
	checkRight->setConnect(SIGNAL_D(CheckRight, p_signal_go_right), doStep, HENDLER_D(DoStep, p_hendler));
	doStep->setConnect(SIGNAL_D(DoStep, p_signal), this, HENDLER_D( root, p_hendler));
}
void root::build()
{
	build_tree();         
	build_connections();
}
void root::exec()
{
	base* in = find("in");
	base* out = find("out");
	data.field = ((input*)in)->in();
	root::coordinates coords = findFirst(data.field);
	data.x = coords.x;
	data.y = coords.y;
	data.state = getUnknown();
	do {
		string text = DataToString(data);
		emitSignal(SIGNAL_D(root, p_signal_check_top), text);
	} while (data.state != getUnknown());
	((output*)out)->out(data.field);
}
void root::p_signal_check_top(string & text) {}
void root::p_hendler(string text)
{
	data = StringToData(text);
}
const string root::goTop = "goTop";
const string root::goBottom = "goBottom";
const string root::goRight = "goRight";
const string root::unknown = "unknown";
const string root::delimeter = ",";
string root::getGoTop() { return goTop; }
string root::getGoBottom() { return goBottom; }
string root::getGoRight() { return goRight; }
string root::getUnknown() { return unknown; }
string root::DataToString(Data data)
{
	string str = data.state + delimeter;
	str += to_string(data.x) + delimeter;
	str += to_string(data.y) + delimeter;
	for (int i = 0; i < data.field.size(); i++)
	{
		for (int j = 0; j < data.field[i].size(); j++)
			str += data.field[i][j];
	}
	return str;
}
Data root::StringToData(string str)
{
	Data data;
	int prPos = 0, nextPos = 0;
	string a[4];
	for (int i = 0; i < 4; i++)
	{
		nextPos = str.find(delimeter, prPos);
		a[i] = str.substr(prPos, nextPos - prPos);
		prPos = nextPos + 1;
	}
	data.state = a[0];
	data.x = stoi(a[1]);
	data.y = stoi(a[2]);
	string field = a[3];
	for (int i = 0; i < 10; i++)
	{
		vector<char> v;
		data.field.push_back(v);
		for (int j = 0; j < 10; j++)
			data.field[i].push_back(field[i * 10 + j]);
	}
	return data;
}
root::coordinates root::findFirst(vector<vector<char>> field)
{
	coordinates c;
	c.x = 0;
	c.y = 0;
	bool top = false, right = false, bottom = false;
	while (true)
	{
		if (c.y != 0)top = field[c.y - 1][c.x] == '1';
		right = field[c.y][c.x + 1] == '1';
		if (c.y + 1 != 10)bottom = field[c.y + 1][c.x] == '1';
		bool flag = top && right || bottom && (right || top);
		if (field[c.y][c.x] == '1' && !flag)break;
		c.y++;
		top = false;
		right = false;
		bottom = false;
	}
	return c;
}
