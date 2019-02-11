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
	if (animationName.empty())
	{
		write += "\n<line ";
		for (int i = 0; i < atter.size(); i++)
		{
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += " />";
		return write;
	}
	else
	{
		write += "\n<line ";
		for (int i = 0; i < atter.size(); i++)
		{
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += " >";
		for (int i = 0; i < animationName.size(); i++)
		{
			string name = animationName[i];
			write += "\n<animate attributeType=\"XML\" ";
			for (int j = 0; j < animation.size(); j++)
			{
				if (name == animation[j].name)
				{
					write += animation[j].key + "=\"" + animation[j].value + "\" ";
				}
			}
			write += " />";
		}
		write += "\n </line> ";
	}
	return write;
}
string line::get(const string &key,const string &key2)
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
