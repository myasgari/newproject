#include <iostream>
#include "shape.h"
#include "rect.h"
#include "circle.h"
#include"ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "scatter.h"
#include "scatterline.h"
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
using namespace std;

int enterChois()
{
	cout << "1-create  2-erase  3-erase all  4-list  5-export  6-animation  7-animate list  8-erase animation  9-exit" << endl;
    int chose;
	cin >> chose;
	return chose;
}
void create(vector<shape *>&shape)
{
	cout << "which object do want to draw ?" << endl;
	cout << "1-circle  2-rect  3-ellipse  4-line  5-polygon  6-polyline  7-scatter 8-scatter line" << endl;
	int in;
	cin >> in;
	cout << "enter the object name :";
	string name;
	cin >> name;
	if (in == 1)
		shape.push_back(new circle(name));
	else if (in == 2)
		shape.push_back(new rect(name));
	else if (in == 3)
		shape.push_back(new ellipse(name));
	else if (in == 4)
		shape.push_back(new line(name));
	else if (in == 5)
		shape.push_back(new polygon(name));
	else if (in == 6)
		shape.push_back(new polyline(name));
	else if (in == 7)
		shape.push_back(new scatter(name));
	else if (in == 8)
		shape.push_back(new scatterline(name));
	shape[shape::Count]->create();
}
void list(const vector<shape *>&shape)
{
	for (int i = 0; i < shape.size(); i++)
	{
		cout << i + 1 << "- name : ";
		cout << shape[i]->sayName();
		cout << " , type : " << typeid(*shape[i]).name() << endl;
	}
}
void erase(vector<shape *>&shape)
{
	list(shape);
	cout << "which object do want to delete plz enter the number : ";
	int  numb;
	cin >> numb;
	for (numb-1; numb < shape.size(); numb++) {
		shape[numb] = shape[numb + 1];
	}
	shape::Count -= 1;
	shape.pop_back();
}
void createFile(vector<shape *>&shape,fstream &pic)
{
	pic << setprecision(2) << fixed;
	string write = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg width=\"1000\" height=\"1000\"\nxmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";
	pic << write;
	for (int i = 0; i < shape.size(); i++)
		pic << shape[i]->Export();
	pic << "\n</svg>";
	cout << "export finish succefully" << endl;
}
void animate(vector<shape *>&shape)
{
	string name;
	cout << "which object do you want to add animate : " << endl;
	list(shape);
	int numb;
	cin >> numb;
	cout << "and enter your animation name : ";
	cin >> name;
	shape[numb - 1]->animatation(name);
}
void animlist(vector<shape *>&shape)
{
	for (int i = 0; i < shape.size(); i++) {
		string aname = shape[i]->sayAnimatName();
		if (aname.empty() == false)
			cout << i + 1 << " - " << shape[i]->sayAnimatName() << endl;
		else
			cout << i + 1 << " -  without animation " << endl;
	}
}
void eraseanim(vector<shape *>&shape)
{
	int number;
	cout << "which object do you want to erase : " << endl;
	animlist(shape);
	cin >> number;
	shape[number - 1]->animOff();
}
