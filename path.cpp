#include "path.h"
#include <string>
using namespace std;

path::path(const std::string &name) :Name(name)
{
}
path::~path()
{
}
string path::returnName()
{
	return Name;
}
string path::Export(std::vector<shape *>&)
{
	if (animationName.empty())
	{
		write += "\n<path ";
		for (int i = 0; i < atter.size(); i++)
		{
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += " />";
		return write;
	}
	else
	{
		write += "\n<path ";
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
		write += "\n </path> ";
	}
	return write;
}
string path::get(const std::string &key, const std::string & key2)
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
		if (i < atter.size())
			return atter[i].value;
		else
			return "this attribute do not exit !!!";
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
