#include "shape.h"
#include <iostream>
#include <string>
using namespace std;
shape::shape()
{
}


shape::~shape()
{
}
string shape::get(const std::string &key, const std::string &key2)
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
