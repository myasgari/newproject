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
string ellipse::Export(vector<shape *>&shape)
{
	if (animationName.empty())
	{
		write += "\n<ellipse ";
		for (int i = 0; i < atter.size(); i++)
		{
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += " />";
		return write;
	}
	else
	{
		write += "\n<ellipse ";
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
		write += "\n </ellipse> ";
	}
	return write;
}
