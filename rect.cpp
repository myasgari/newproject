#include "rect.h"
#include <string>
#include <iostream>
using namespace std;


rect::rect(const string &name) : Name(name)
{
}
rect::~rect()
{
}
string rect::returnName()
{
	return Name;
}
string rect::Export()
{
	write += "\n<rect ";
	for (int i = 0; i < atter.size(); i++)
	{
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " />";
	return write;
}
string rect::get(const string &key)
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
