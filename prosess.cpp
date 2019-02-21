#include <iostream>
#include "shape.h"
#include "rect.h"
#include "circle.h"
#include"ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "scatter.h"
#include "text.h"
#include "path.h"
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
void load(vector<shape *>&);
void create(const string &, vector<shape *>&);
void set(const string &, vector<shape *>&);
void Export(const string &,vector<shape *>&);
void list(const string &,const vector<shape *>&);
void clear(const string &, vector<shape *>&);
void getatt(const string &, vector<shape *>&);
void clearall( vector<shape *>&);
void animate(const string &, vector<shape *>&);
void help(const string &);
void enterpross(const string &enter,vector<shape *>&shape)
{
	if (enter.find("help") != string::npos)
		help(enter);
	else if (enter.find("create") != string::npos)
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
		Export(enter, shape);
	else if (enter.find("list") != string::npos)
		list(enter, shape);
	else if (enter.find("clear all") != string::npos)
		clearall(shape);
	else if (enter.find("clear") != string::npos)
		clear(enter, shape);
	else if (enter.find("get") != string::npos)
		getatt(enter, shape);
	else if (enter.find("animation") != string::npos)
		animate(enter, shape);
	else if (enter.find("load") != string::npos)
		load(shape);
	else
		cout << "this  is not define\n";
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
	else if (enter.find("plot") != string::npos)
	{
		string name = enter.substr(12);
		shape.push_back(new scatter(name));
	}
	else if (enter.find("text") != string::npos)
	{
		string name = enter.substr(12);
		shape.push_back(new text(name));
	}
	else if (enter.find("path") != string::npos)
	{
		string name = enter.substr(12);
		shape.push_back(new path(name));
	}
	else
		cout << "this shape is not define ";
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
				int pos = enter.find('(');;
				int poss = enter.find(')');;
				height = enter.substr(pos + 1, poss - pos - 1);
			}
			if (enter.find("width") != string::npos)
			{
				int pos = enter.find('(');;
				int poss = enter.find(')');;
				width = enter.substr(pos + 1, poss - pos - 1);
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
void Export(const string &enter,vector<shape *>&shape)
{
	string name = "C:\\Users\\Mehr\\Documents\\Visual Studio 2017\\Projects\\Project6\\export\\";
	int pos = enter.find('(');
	int poss = enter.find(')');
	string fileName = enter.substr(pos + 1, poss - pos - 1);
	name += fileName;
	fstream pic(name, ios::out);
	if (!pic) {
		cout << "file could not be open !!!";
		exit(EXIT_FAILURE);
	}
	if (width.empty() || height.empty())
	{
		cout << "\n plz at first set width and height of picture \n";
	}
	else
	{
		pic << "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg width=\"" + width + "\" height=\"" + height + "\"\nxmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"> \n";
		for (int i = 0; i < shape.size(); i++)
			pic << shape[i]->Export(shape);
		pic << "\n</svg>";
	}
	pic.close();
}
void list(const string &enter,const vector<shape *>&shape)
{
	if (enter.find("animate") != string::npos)
	{
		int i = 0;
		int pos = enter.find_last_of(" ");
		string shapeName = enter.substr(pos + 1);
		for (i; i < shape.size(); i++)
		{
			if (shapeName == shape[i]->returnName())
				break;
		}
		for (int j = 0; j < shape[i]->animationName.size(); j++)
		{
			cout << shape[i]->animationName[j] << endl;
		}
	}
	else
	{
		for (int i = 0; i < shape.size(); i++)
		{
			cout << i + 1 << "- name : ";
			cout << shape[i]->returnName();
			cout << " , type : " << typeid(*shape[i]).name() << endl;
		}
	}
}
void clear(const string &enter, vector<shape *>&shape)
{
	int pos = enter.find('>');
	if (pos == -1)
	{
		int i = 0;
		for (i; i < shape.size(); i++)
		{
			string clearName = enter.substr(6);
			string name = shape[i]->returnName();
			if (name == clearName)
				break;
		}
		for (i; i < shape.size() - 1; i++)
		{
			shape[i] = shape[i + 1];
		}
		shape.pop_back();
	}
	else
	{
		int posi = enter.find_last_of('-');
		string shapeName = enter.substr(6, posi - 6);
		int i = 0;
		int j = 0;
		for (i; i < shape.size(); i++)
		{
			string name = shape[i]->returnName();
			if (name == shapeName)
				break;
		}
		int posit = enter.find_last_of('>');
		string animName = enter.substr(posit + 1);
		for (j; j < shape[i]->animationName.size(); j++)
		{
			if (animName == shape[i]->animationName[j])
				break;
		}
		for (j; j < shape[i]->animationName.size() - 1; j++)
		{
			shape[i]->animationName[j] = shape[i]->animationName[j + 1];
		}
		shape[i]->animationName.pop_back();
	}
}
void getatt(const string &enter, vector<shape *>&shape)
{
	int f = enter.find('>');
	int l = enter.find_last_of('>');
	int i = 0;
	for (i; i < shape.size(); i++)
	{
		string name = shape[i]->returnName();
		if (enter.find(name) != string::npos)
			break;
	}
	if (f == l)
	{
		int posion = enter.find_first_of('>');
		string key = enter.substr(posion + 1);
		key += " ";
		cout << shape[i]->get(key) << endl;
	}
	else
	{
		int x = enter.find('>');
		int y = enter.find_last_of('-');
		string shapeName = enter.substr(x + 1, y - x - 1);
		int z = enter.find_last_of('>');
		string key = enter.substr(z + 1);
		key += " ";
		cout << shape[i]->get(shapeName, key) << endl;
	}
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
	else
	{
		for (j; j < shape[i]->animationName.size(); j++)
		{
			if (shape[i]->animationName[j] == value)
				avilable = true;
		}
		if (avilable == false)
			shape[i]->animationName.push_back(value);
	}
}
void load(vector<shape *>&shape)
{
	fstream load("load.txt", ios::in);
	if (!load) {
		cout << "file could not be open !!!";
		exit(EXIT_FAILURE);
	}
	string text;
	while (!load.eof())
	{
		getline(load, text);
		if (text.find("#") != string::npos)
			continue;
		int size = text.size();
//		text = text.substr(0, size - 1);  //if they had ; in the last of them
		enterpross(text, shape);
	}
	load.clear();
	load.seekg(0);
}
void help(const string &enter)
{
	string name = enter.substr(5);
	cout << "the example write on a **  **\n";
	if (name == "create")
	{
		cout << "for creating object at first you should write create, then the object that you want to draw,";
		cout << "and at end the name of object .becarefull the name must be uniqe and name do not chose for anothe object\n**create circle c1**\n";
	}
	else if (name == "set")
	{
		cout << "for exporting image you must set height and width \n**set height (900)**\n**set width (800)**\n";
		cout << "for seting of attribut of object you should write set , then write a object name that you want to set .after that write ->";
		cout << "and the name of attribute and value of the attribute pay attention you must have enter one space between attribute name and value\n**set c1->r (20)**\n";
		cout << "and for animation such as above write set , name of object -> , animation name -> and attribute name and value \n**set c1->anim2->from (20)**\n";
	}
	else if (name == "export")
	{
		cout << "for drawing your object your shape on a .svg file you shaould write export and in pranteses the file name.\n**export (pic.svg)**\n";
	}
	else if (name == "list")
	{
		cout << "for displaying the object or your shape you should write list and after ,a list of shape apper \n**list**\n";
		cout << "and list of animation of a shape at first write list , wite animte  and at end wite the nam eof object\n**list animate c1**\n";
	}
	else if (name == "clearall")
		cout << "after write clearall all of bject that you create delete and there is no object\n**clearall**\n";
	else if (name == "clear")
	{
		cout << "for clearing one object at first you should write clear and after that the name of the class that you want to delet \n**clear c1**\n";
		cout << "and for clear animation of an object at firct write clear after that write object name and -> and at end animation name \n**clear c1->anim2**\n";
	}
	else if (name == "get")
	{
		cout << "for geting the arrtibute value of an on object at first you should write get after that write the shape name and -> and  at end write the attribute name that you want to know it's value \n**get c1->r**\n";
		cout << "and for geting know about a animation such as above get ,shape name,->,animation name,->,and attribuation name \n**get c1->anim2->to**\n";
	}
	else if (name == "animation")
	{
		cout << "for seting animation for your shape at first you should write animation and after that object name and at end a animation name becarefull animation name must be unique \n**animation c1 anim2**\n";
	}
	else if (name == "load")
	{
		cout << "writing thing on ___ is deficult if you want you can write your code on file after that write load and all thing accur very simple\n**load**\n";
	}
	else
		cout << "noooooooo";
}
