#include "ellipse.h"

#include <string>
#include <iostream>
using namespace std;


ellipse::ellipse(const string &name) :Name(name)
{
}

ellipse::~ellipse()
{
}
string ellipse::returnName()
{
	return Name;
}
string ellipse::Export()
{
	write += "\n<ellipse ";
	for (int i = 0; i < atter.size(); i++)
	{
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " />";
	return write;
}
string ellipse::get(const string &key)
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
