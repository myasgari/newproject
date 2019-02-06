#include <iostream>
#include "shape.h"
#include "rect.h"
#include "circle.h"
#include"ellipse.h"
#include "line.h"
//#include "polygon.h"
#include "polyline.h"
//#include "scatter.h"
//#include "scatterline.h"
#include "atterb.h"
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <stdexcept>
using namespace std;
void create(const string &, vector<shape *>&);
void set(const string &, vector<shape *>&);
void Export(vector<shape *>&, fstream &);
void list(const vector<shape *>&);
void clear(const string &, vector<shape *>&);
void getatt(const string &, vector<shape *>&);
void clearall( vector<shape *>&);
void enterpross(const string &enter,vector<shape *>&shape,fstream &pic)
{
	if (enter.find("create") != string::npos)
		create(enter,shape);
	if (enter.find("set") != string::npos)
		set(enter, shape);
	if (enter.find("export") != string::npos)
		Export(shape, pic);
	if (enter.find("list") != string::npos)
		list(shape);
	if (enter.find("clearall") != string::npos)
		clearall(shape);
	if (enter.find("clear") != string::npos)
		clear(enter, shape);
	if (enter.find("get") != string::npos)
		getatt(enter, shape);
}
void create(const string &enter, vector<shape *>&shape)
{
	if (enter.find("circle") != string::npos)
	{
		string name = enter.substr(14);
		shape.push_back(new circle(name));
	}
	else if (enter.find("rectangle") != string::npos)
	{
		string name = enter.substr(17);
		shape.push_back(new rect(name));
	}
	else if (enter.find("ellipse") != string::npos)
	{
		string name = enter.substr(15);
		shape.push_back(new ellipse(name));
	}
	else if (enter.find("polyline") != string::npos)
	{
		string name = enter.substr(16);
		shape.push_back(new polyline(name));
	}
	else if (enter.find("line") != string::npos)
	{
		string name = enter.substr(12);
		shape.push_back(new line(name));
	}
}
void set(const string &enter, vector<shape *>&shape)
{
	int i = 0;
	atterb att;
	for (i; i < shape.size(); i++)
	{
		string name = shape[i]->returnName();
	if (enter.find(name) != string::npos)
			break;
	}
	int posion = enter.find_first_of('>');
	int posions = enter.find_first_of('(');
	string newkey = enter.substr(posion + 1, posions - posion - 1);
	int posionss = enter.find_last_of(')');
	string newvalue= enter.substr(posions + 1, posionss - posions - 1);
	att.key = newkey;
	att.value = newvalue;
	shape[i]->atter.push_back(att);
}
void Export(vector<shape *>&shape,fstream &pic)
{
	pic << "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg width=\"1000\" height=\"1000\"\nxmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"> \n";
	for (int i = 0; i < shape.size(); i++)
		pic << shape[i]->Export();
	pic << "\n</svg>";
}
void list(const vector<shape *>&shape)
{
		for (int i = 0; i < shape.size(); i++)
		{
			cout << i + 1 << "- name : ";
			cout << shape[i]->returnName();
			cout << " , type : " << typeid(*shape[i]).name() << endl;
		}
}
void clear(const string &enter, vector<shape *>&shape)
{
	int i = 0;
	string eraseName = enter.substr(6);
	for (i; i < shape.size(); i++)
	{
		if (eraseName == shape[i]->returnName())
			break;
	}
	if (i < shape.size()) {
		for (i; i < shape.size(); i++)
		{
			shape[i - 1] = shape[i];
		}
		shape.pop_back();
	}
	else
		shape.pop_back();
}
void getatt(const string &enter, vector<shape *>&shape)
{
	int i = 0;
	for (i; i < shape.size(); i++)
	{
		string name = shape[i]->returnName();
		if (enter.find(name) != string::npos)
			break;
	}
	int posion = enter.find_first_of('>');
	string key = enter.substr(posion + 1);
	key += " ";
	cout << shape[i]->get(key) << endl;
}
void clearall( vector<shape *>&shape)
{
	for (int i = 0; i < shape.size(); i++)
		shape.pop_back();
}
