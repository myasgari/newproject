#include "rect.h"
#include <iostream>
#include <string>

using namespace std;
rect::rect(const string &name)
{
	this ->name =name;
}
rect::~rect()
{
}
void rect::setXandY()
{
	cout << "please enter the x and y for your position in picture" << endl;
	cout << "enter x = ";
	cin >> X;
	cout << "enter y = ";
	cin >> Y;
}
void rect::setColor()
{
  string holdstroke;
  string holdopacity;
  cout<<"please enter the color of your regtangel"<<endl;
  cin>>color;
  cout<<"if you want stroke color enter yes else enter no "<<endl;
  cin>>holdstroke;
  if ("no" != holdstroke){
		cout<< "stroke color = ";
    cin >>strokecolor;
  }
  cout<<"if you want opacity enter yes else enter no "<<endl;
  cin>>holdopacity;
  if ("no" != holdopacity){
		cout<<"opacity = ";
    cin >>opacity;
  }
}
void rect::setSize()
{
  cout<<"enter the hight and widht of regtangel"<<endl;
  cout<< "enter the hight = ";
  cin>>hight;
  cout<<"enter the widht = ";
  cin>>widht;
}
void rect::setStrokewidth()
{
	string holdstrokwidth;
	cout<<"if you want stroke width enter yes else enter no "<<endl;
	cin>>holdstrokwidth;
	if ("no" != holdstrokwidth){
		cout<<"stroke width = ";
		cin>>strokewidth;
	}
}
