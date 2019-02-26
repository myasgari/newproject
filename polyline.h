#pragma once
#include "shape.h"
#include <string>
class polyline :public shape
{
public:
	polyline();
	polyline(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	~polyline();
private:
	std::string Name;
	std::string write;
};
