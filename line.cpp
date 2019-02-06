#include "line.h"

#include <string>
#include <iostream>
using namespace std;

line::line(const string & name):Name(name)
{
}
line::~line()
{
}
string line::returnName()
{
	return Name;
}
string line::Export()
{
	write += "\n<line ";
	for (int i = 0; i < atter.size(); i++)
	{
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " />";
	return write;
}
string line::get(const string &key)
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
