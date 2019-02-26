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
string rect::Export(vector<shape *>&shape)
{
	if (animationName.empty())
	{
		write += "\n<rect ";
		for (int i = 0; i < atter.size(); i++)
		{
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += " />";
		return write;
	}
	else
	{
		write += "\n<rect ";
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
		write += "\n </rect> ";
	}
	return write;
}
