#pragma once
#include <string>
#include "shape.h"
class path :public shape
{
public:
	path(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	~path();
private:
	std::string Name;
	std::string write;
};
