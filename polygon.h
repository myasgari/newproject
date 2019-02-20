#pragma once
#include "shape.h"
#include <string>
class polygon :public shape
{
public:
	polygon(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	virtual std::string get(const std::string &, const std::string & = "") override;
	~polygon();
private:
	std::string Name;
	std::string write;
};
