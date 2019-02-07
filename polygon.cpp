#include "polygon.h"

#include <string>
#include <iostream>
using namespace std;


polygon::polygon(const string &name):Name(name)
{
}
polygon::~polygon()
{
}
string polygon::returnName()
{
	return Name;
}
string polygon::Export()
{
	write += "\n<polygon ";
	for (int i = 0; i < atter.size(); i++)
	{
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " />";
	return write;
}
string polygon::get(const string &key)
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
