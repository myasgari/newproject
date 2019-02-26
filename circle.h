#pragma once
#include "shape.h"
#include <string>
class circle :public shape
{
public:
	circle();
	circle(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override ;
	~circle();
private:
	std::string Name;
	std::string write;
};
