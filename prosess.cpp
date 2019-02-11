#include <iostream>
#include "shape.h"
#include "rect.h"
#include "circle.h"
#include"ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
//#include "scatter.h"
//#include "scatterline.h"
#include "atterb.h"
#include "animation.h"
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <stdexcept>
using namespace std;
string width, height;
void create(const string &, vector<shape *>&);
void set(const string &, vector<shape *>&);
void Export(vector<shape *>&, fstream &);
void list(const vector<shape *>&);
void clear(const string &, vector<shape *>&);
void getatt(const string &, vector<shape *>&);
void clearall( vector<shape *>&);
void animate(const string &, vector<shape *>&);
void enterpross(const string &enter,vector<shape *>&shape,fstream &pic)
{
	if (enter.find("create") != string::npos)
	{
		bool canCreate = true;
		for (int i = 0; i < shape.size(); i++)
		{
			int pos = enter.find_last_of(" ");
			string name = enter.substr(pos + 1);
			if (shape[i]->returnName() == name)
				canCreate = false;
		}
		if (canCreate)
			create(enter, shape);
		else
			cout << "try again this name available you can not enter repetitious name " << endl;
	}
	else if (enter.find("set") != string::npos)
		set(enter, shape);
	else if (enter.find("export") != string::npos)
		Export(shape, pic);
	else if (enter.find("list") != string::npos)
		list(shape);
	else if (enter.find("clear all") != string::npos)
		clearall(shape);
	else if (enter.find("clear") != string::npos)
		clear(enter, shape);
	else if (enter.find("get") != string::npos)
		getatt(enter, shape);
	else if (enter.find("animation") != string::npos)
		animate(enter, shape);
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
	else if (enter.find("polygon") != string::npos)
	{
		string name = enter.substr(15);
		shape.push_back(new polygon(name));
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
	int f = enter.find('>');
	int l = enter.find_last_of('>');
	if (f == l)
	{
		int i = 0;
		atterb att;
		for (i; i < shape.size(); i++)
		{
			string name = shape[i]->returnName();
			int pos = enter.find_first_of('-');
			string shapeName = enter.substr(4, pos - 4);
			if (shapeName == name)
				break;
		}
		if (i < shape.size())
		{
			int posion = enter.find_first_of('>');
			int posions = enter.find_first_of('(');
			string newkey = enter.substr(posion + 1, posions - posion - 1);
			int posionss = enter.find_last_of(')');
			string newvalue = enter.substr(posions + 1, posionss - posions - 1);
			att.key = newkey;
			att.value = newvalue;
			shape[i]->atter.push_back(att);
		}
		else
		{
			if (enter.find("height") != string::npos)
			{
				int pos = enter.find_first_of('(');
				int poss = enter.find_last_of(')');
				height = enter.substr(pos + 1, poss - 2);
			}
			if (enter.find("width") != string::npos)
			{
				int pos = enter.find_first_of('(');
				int poss = enter.find_last_of(')');
				width = enter.substr(pos + 1, poss - 3);
			}
		}
	}
	else
	{
		int i = 0;
		int pos = enter.find('-');
		string shapeName = enter.substr(4, pos - 4);
		for (i; i < shape.size(); i++)
		{
			if (shapeName == shape[i]->returnName())
				break;
		}
		animation a;
		int fa = enter.find('>');
		int la = enter.find_last_of('-');
		string name = enter.substr(fa + 1, la - fa - 1);
		int fb = enter.find_last_of('>');
		int lb = enter.find('(');
		string key = enter.substr(fb + 1, lb - fb - 1);
		int fc = enter.find('(');
		int lc = enter.find_last_of(')');
		string value = enter.substr(fc + 1, lc - fc - 1);
		a.name = name;
		a.key = key;
		a.value = value;
		shape[i]->animation.push_back(a);
	}
}
void Export(vector<shape *>&shape,fstream &pic)
{
	pic << "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg width=\""+ width +"\" height=\""+height+"\"\nxmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"> \n";
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
	for (i; i < shape.size(); i++)
	{
		string clearName = enter.substr(6);
		string name = shape[i]->returnName();
		if (name == clearName)
			break;
	}
	for (i; i < shape.size()-1; i++)
	{
		shape[i] = shape[i + 1];
	}
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
void clearall( vector<shape *>&shap)
{
	vector<shape *>shape;
	shap = shape;
}
void animate(const string &enter, vector<shape *>&shape)
{
	int i = 0;
	int j = 0;
	bool avilable = false;
	int pos = enter.find_last_of(" ");
	string name = enter.substr(10, pos - 10);
	string value = enter.substr(pos + 1);
	for (i; i < shape.size(); i++)
	{
		string shapeName = shape[i]->returnName();
		if (name == shapeName)
			break;
	}
	if (shape[i]->animationName.empty())
		shape[i]->animationName.push_back(value);
	for (j; j < shape[i]->animationName.size(); j++)
	{
		if (shape[i]->animationName[j] == value)
			avilable = true;
	}
	if (avilable == false)
		shape[i]->animationName.push_back(value);
}
