#include "scatter.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "circle.h"
#include "polyline.h"
#include "atterb.h"
using namespace std;

scatter::scatter(const string &name) :Name(name)
{
}
scatter::~scatter()
{
}
string scatter::returnName()
{
	return Name;
}
string scatter::Export(vector<shape *>&shape)
{
	/*	string fileName;
	string name = "C:\\Users\\Mehr\\Documents\\Visual Studio 2017\\Projects\\Project6\\data\\";*/
	string type;
	int i = 0;
	float x, y;
	float wMax = 0, hMax = 0;
	atterb a;
	int size;
	fstream data("data.txt", ios::in);
	if (!data) {
		cout << "file could not be open !!!";
		exit(EXIT_FAILURE);
	}
	/*	int j = 0;
	for (j; j < atter.size(); j++)
	{
	if (atter[j].key == "data ")
	{
	fileName = atter[j].value;
	break;
	}
	}
	for (j; j < atter.size() - 1; j++)
	{
	atter[j] = atter[j + 1];
	}
	name += fileName;
	fstream data(name, ios::in);
	if (!data) {
	cout << "file could not be open !!!";
	exit(EXIT_FAILURE);
	}
	*/
	for (i; i < atter.size(); i++)
	{
		if (atter[i].value == "scatter")
		{
			type = "scatter";
			break;
		}
		if (atter[i].value == "line")
		{
			type = "line";
			break;
		}
	}
	write += "\n<rect ";
	for (int i = 0; i < atter.size(); i++)
	{
		if (atter[i].key == "type ")
			continue;
		write += atter[i].key + "=\"" + atter[i].value + "\" ";
	}
	write += " fill =\"white\" stroke-width =\"3\"  stroke = \"black\" />";
	if (type == "scatter")
	{
		int counter = 0;
		while (!data.eof())
		{
			data >> x >> y;
			if (x > wMax)
				wMax = x;
			if (y > hMax)
				hMax = y;
			string name = "s" + std::to_string(counter);
			shape.push_back(new circle(name));
			size = shape.size() - 1;
			a.key = "fill ";
			a.value = "blue";
			shape[size]->atter.push_back(a);
			a.key = "r ";
			a.value = "10";
			shape[size]->atter.push_back(a);
			a.key = "cx ";
			a.value = std::to_string(x);
			shape[size]->atter.push_back(a);
			a.key = "cy ";
			a.value = std::to_string(y);
			shape[size]->atter.push_back(a);
			counter++;
		}
	}
	if (type == "line")
	{
		string value;
		shape.push_back(new polyline("ch"));
		size = shape.size() - 1;
		a.key = "fill ";
		a.value = "none";
		shape[size]->atter.push_back(a);
		a.key = "stroke ";
		a.value = "orange";
		shape[size]->atter.push_back(a);
		a.key = "stroke-width ";
		a.value = "3";
		shape[size]->atter.push_back(a);
		a.key = "points ";
		while (!data.eof())
		{
			data >> x >> y;
			if (x > wMax)
				wMax = x;
			if (y > hMax)
				hMax = y;
			value += std::to_string(x);
			value += ",";
			value += std::to_string(y) + " ";
		}
		a.value = value;
		shape[size]->atter.push_back(a);
	}
	data.clear();
	data.seekg(0);
	return write;
}
string scatter::get(const std::string &key, const std::string & key2)
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
