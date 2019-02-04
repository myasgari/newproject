#include <iostream>
#include "shape.h"
//#include "rect.h"
#include "circle.h"
//#include"ellipse.h"
//#include "line.h"
//#include "polygon.h"
//#include "polyline.h"
//#include "scatter.h"
//#include "scatterline.h"
//#include "atter.h"
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <stdexcept>
using namespace std;
void create(const string &, vector<shape *>&);
void set(const string &, vector<shape *>&);
void enterpross(const string &enter,vector<shape *>&shape)
{
	if (enter.find("create") != string::npos)
		create(enter,shape);
	if (enter.find("set") != string::npos)
		set(enter, shape);
}
void create(const string &enter, vector<shape *>&shape)
{
	if (enter.find("circle") != string::npos)
	{
		string name = enter.substr(14);
		shape.push_back(new circle(name));
	}
}
void set(const string &enter, vector<shape *>&shape)
{

}
