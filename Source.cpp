#include <iostream>
//#include "shape.h"
//#include "rect.h"
//#include "circle.h"
//#include"ellipse.h"
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void enterpross(const string &);
int main()
{
	string enter;
	while (1)
	{
		getline(cin, enter);
		if (enter == "exit")
			break;
		enterpross(enter);
	}
	return 0;
}
