#pragma once
#include "shape.h"
#include <string>
class ellipse :public shape
{
public:
	ellipse(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	~ellipse();
private:
	std::string Name;
	std::string write;
};
