#pragma once
#include <string>
#include "shape.h"
class text :public shape
{
public:
	text(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	~text();
private:
	std::string Name;
	std::string write;
};
