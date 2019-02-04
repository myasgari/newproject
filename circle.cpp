#include "circle.h"
#include <string>
using namespace std;

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
string circle::Export()
{
	write += "\n<circle ";
	for (int i = 0; i < atter.size(); i++)
	{
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " />";
	return write;
}
