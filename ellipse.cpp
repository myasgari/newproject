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
string ellipse::get(const string &key,const string &key2)
{
	if (key2.empty())
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
	else
	{
		int i = 0;
		for (i; i < animation.size(); i++)
		{
			if (animation[i].name == key && animation[i].key == key2)
				break;
		}
		return animation[i].value;
	}
}
