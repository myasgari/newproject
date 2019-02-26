#include "scatter.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "text.h"
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
/*		string fileName;
	string name = "C:\\Users\\Mehr\\Documents\\Visual Studio 2017\\Projects\\Project6\\data\\";*/
	string type;
	string title;
	int i = 0;
	float x, y;
	int wMax = 0, hMax =INT_MAX;
	atterb a;
	float X, Y, H , W;
	int size;
	fstream data("data.txt", ios::in);
	if (!data) {
		cout << "file could not be open !!!";
		exit(EXIT_FAILURE);
	}
	int find = 0;
	for (find; find < atter.size(); find++)
	{
		if (atter[find].key == "title ")
			break;
	}
	title = atter[find].value;
	find = 0;
	for (find; find < atter.size(); find++)
	{
	if (atter[find].key == "x ")
	break;
	}
	X = std::stof(atter[find].value);
	find = 0;
	for (find; find < atter.size(); find++)
	{
	if (atter[find].key == "y ")
	break;
	}
	Y = std::stof(atter[find].value);
	find = 0;
	for (find; find < atter.size(); find++)
	{
	if (atter[find].key == "width ")
	break;
	}
	W = std::stof(atter[find].value);
	find = 0;
	for (find; find < atter.size(); find++)
	{
	if (atter[find].key == "height ")
	break;
	}
	H = std::stof(atter[find].value);
	write += "\n<text x=\"" + std::to_string(((W / 2) + X) -(title.size()*10)) + "\" y=\"" + std::to_string(Y - 10) + "\" font-family=\"Ubuntu\" font-size=\"35\">" + title + "</text>";
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
		if (atter[i].key == "type " || atter[i].key == "title ")
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
			if (y < hMax)
				hMax = y;
			string name = "ch" + std::to_string(counter);
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
			if (y < hMax)
				hMax = y;
			value += std::to_string(x);
			value += ",";
			value += std::to_string(y) + " ";
		}
		a.value = value;
		shape[size]->atter.push_back(a);
	}
	write+= "\n<text x=\"" + std::to_string(wMax ) + "\" y=\"" + std::to_string(Y+H +(H*.01)) + "\" font-family=\"Ubuntu\" font-size=\"40\">" + "|"+ "</text>";
	write += "\n<text x=\"" + std::to_string(wMax)  + "\" y=\"" + std::to_string(Y + H + (H*.3)) + "\" font-family=\"Ubuntu\" font-size=\"20\">" + std::to_string(hMax) + "</text>";
	write += "\n<text x=\"" + std::to_string(X-(X*.1)) + "\" y=\"" + std::to_string(hMax) + "\" font-family=\"Ubuntu\" font-size=\"40\">" + "__" + "</text>";
	write += "\n<text x=\"" + std::to_string(X - (X*.6)) + "\" y=\"" + std::to_string(hMax) + "\" font-family=\"Ubuntu\" font-size=\"20\">" + std::to_string(wMax) + "</text>";
	data.clear();
	data.seekg(0);
	return write;
}
