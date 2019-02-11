#pragma once
#include "atterb.h"
#include "animation.h"
#include <vector>
#include <string>
class shape
{
public:
	shape();
	virtual std::string returnName() = 0;
	virtual std::string Export() = 0;
	virtual std::string get(const std::string &,const std::string & ="") = 0;
	~shape();
	std::vector<atterb>atter;
	std::vector<animation>animation;
	std::vector<std::string>animationName;
};
