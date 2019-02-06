#include "polyline.h"

#include <string>
#include <iostream>
using namespace std;

polyline::polyline(const string &name):Name(name)
{
}
polyline::~polyline()
{
}
string polyline::returnName()
{
	return Name;
}
string polyline::Export()
{
	write += "\n<polyline ";
	for (int i = 0; i < atter.size(); i++)
	{
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " />";
	return write;
}
string polyline::get(const string &key)
{
	int i = 0;
	for (i; i < atter.size(); i++)
	{
		string name = atter[i].key;
		if (key == name)
			break;
	}
	return atter[i].value;
}
