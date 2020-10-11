#pragma once
#ifndef BASE_H
#define BASE_H
#include <vector>
#include <string> 
using namespace std;
class base;
typedef void (base::* TYPE_SIGNAL)(string &);
typedef void (base::* TYPE_HANDLER)(string );
class base {
protected:
	string name;
	base* parent;
	int ready;
	int n_cl;
	struct sh
	{
		base * ob_base;
		TYPE_SIGNAL s_ignal;
		TYPE_HANDLER h_endler;
	};
	vector<sh*> connects; 
public:
	vector <base*> list;
	base(base* parent);
	base(base* parent, string name);
	~base();
	string getName();
	void setName(string name);
	int getReady();
	void setReady(int ready);
	int get_n_cl();
	void set_n_cl(int cl);
	base* find_by_path(vector<string>& path,int level);
	base* find(string name);
	void transform_url(string url, vector<string>& path);
	void print();
	void print_ready();
	void print_tree(int level);
	void setConnect(TYPE_SIGNAL s_ignal, base* ob_hend, TYPE_HANDLER
		h_endler);
	void deleteConnect(TYPE_SIGNAL s_ignal, base* ob_hend, TYPE_HANDLER
		h_endler);
	void emitSignal(TYPE_SIGNAL s_ignal, string& command);
};

#endif
