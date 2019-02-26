#pragma once
#include "shape.h"
#include <string>
class line:public shape
{
public:
	line(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	~line();
private:
	std::string Name;
	std::string write;
};
