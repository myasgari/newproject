#include "circle.h"
#include <string>
#include <iostream>
using namespace std;
circle::circle()
{}
circle::circle(const string &name): Name(name)
{
}
circle::~circle()
{
}
string circle::returnName()
{
	return Name;
}
string circle::Export(vector<shape *>&shape)
{
	if (animationName.empty())
	{
		write += "\n<circle ";
		for (int i = 0; i < atter.size(); i++)
		{
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += " />";
		return write;
	}
	else
	{
		write += "\n<circle ";
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
		write += "\n </circle> ";
	}
	return write;
}
