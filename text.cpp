#include "text.h"
#include <string>
using namespace std;

text::text(const string &name):Name(name)
{
}
text::~text()
{
}
string text::returnName()
{
	return Name;
}
string text::Export(std::vector<shape *>&shape)
{
	if (animationName.empty())
	{
		int j = 0;
		write += "\n<text ";
		for (int i = 0; i < atter.size(); i++)
		{
			if (atter[i].key == "text ")
				continue;
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += ">";

		for (j; j < atter.size(); j++)
		{
			if (atter[j].key == "text ")
				break;
		}
		write += atter[j].value;
		write += " </text>";
		return write;
	}
	else
	{
		int j = 0;
		write += "\n<text ";
		for (int i = 0; i < atter.size(); i++)
		{
			if (atter[i].key == "text ")
				continue;
			write += atter[i].key + "=\"" + atter[i].value + "\" ";
		}
		write += ">";

		for (j; j < atter.size(); j++)
		{
			if (atter[j].key == "text ")
				break;
		}
		write += atter[j].value;
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
		write += "\n </text> ";
		return write;
	}
}
