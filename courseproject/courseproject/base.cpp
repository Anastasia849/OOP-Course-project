#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip> 

base::base(base* parent) { this->parent = parent; }
base::base(base* parent, string name)
{
	this->parent = parent;
	this->name = name;
	parent->list.push_back(this);
}
string base::getName() { return name; }
void base::setName(string name) { this->name = name; }
int base::getReady() { return this->ready; }
void base::setReady(int ready) { this->ready = ready; }
int base::get_n_cl() { return this->n_cl; }
void base::set_n_cl(int cl) { this->n_cl = cl; }
base * base::find_by_path(vector<string>& path, int level)
{
	base* p = NULL;
	if (path.size() == 1) p = find(path[0]);
	else
	{
		if (!parent && path[0] == getName()) level = 1;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i]->getName() == path[level])
			{
				if (level == path.size() - 1)
				{
					p = list[i];
					break;
				}
				list[i]->find_by_path(path, level + 1);
			}
		}
	}
	return p;
}
base* base::find(string name)
{
	base* victory = NULL;
	if (name == getName().c_str())victory = this;
	else if (list.size() > 0)
	{
		for (int i = 0; i < list.size(); i++)
		{
			victory = list[i]->find(name);
			if (victory != NULL) break;
		}
	}
	return victory;
}
void base::transform_url(string url, vector<string>& path)
{
	string str = "";
	for (int i = 0; i < url.length(); i++)
	{
		if (url[i] == '/')
		{
			if (str != "")
				path.push_back(str);
			str = "";
			continue;
		}
		str += url[i];
	}
	path.push_back(str);
}
void base::print()
{
	cout << getName().c_str();
	for (int i = 0; i < list.size(); i++)
	{
		cout << "  " << list[i]->getName().c_str();
	}
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->list.size() != 0)
		{
			cout << "\n";
			list[i]->print();
		}
	}
}
void base::print_ready()
{
	if (parent == NULL) cout << "The object " << this->name << "is ready";
	for (int i = 0; i < list.size(); i++)
	{
		cout << "\nThe object " << list[i]->getName().c_str();
		if (list[i]->ready > 0)
			cout << " is ready";
		else
			cout << " is not ready";
		if (list[i]->list.size() != 0)
			list[i]->print_ready();
	}
}
void base::setConnect(TYPE_SIGNAL s_ignal, base* ob_hend, TYPE_HANDLER
	h_endler)
{
	sh* value;
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->s_ignal == s_ignal && connects[i]->ob_base == ob_hend && connects[i]->h_endler == h_endler)return;
	}
	value = new sh();
	value->ob_base = ob_hend;
	value->h_endler = h_endler;
	value->s_ignal = s_ignal;
	connects.push_back(value);
}
void base::deleteConnect(TYPE_SIGNAL s_ignal, base* ob_hend, TYPE_HANDLER
	h_endler)
{
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->s_ignal == s_ignal && connects[i]->ob_base == ob_hend && connects[i]->h_endler == h_endler)
		{
			delete connects[i];
			connects.erase(connects.begin() + i);
		}
	}
}
void base::emitSignal(TYPE_SIGNAL s_ignal, string& command)
{
	TYPE_HANDLER hendler;
	(this->*s_ignal)(command);
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->s_ignal == s_ignal)
		{
			hendler = connects[i]->h_endler;
			(connects[i]->ob_base->*hendler)(command);
		}
	}
}
void base::print_tree(int level)
{
	if (!parent)
	{
		cout << getName();
		level = 1;
	}
	for (int i = 0; i < list.size(); i++)
	{
		cout << '\n' << setw(level * 4) << ' ';
		cout << list[i]->getName();
		if (list[i]->list.size() != 0)
			list[i]->print_tree(level + 1);
	}
}
base::~base()
{
	for (int i = 0; i < list.size(); i++)
		delete list[i];
	for (int i = 0; i < connects.size(); i++)
		delete connects[i];
}
