#include "rect.h"
#include <string>
using namespace std;


rect::rect(const string &name): Name(name)
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
