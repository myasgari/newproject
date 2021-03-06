#pragma once
#include "shape.h"
#include <string>
class rect :public shape
{
public:
	rect(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	~rect();
private:
	std::string Name;
	std::string write;
};
