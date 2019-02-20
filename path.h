#pragma once
#include <string>
#include "shape.h"
class path :public shape
{
public:
	path(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	virtual std::string get(const std::string &, const std::string & = "") override;
	~path();
private:
	std::string Name;
	std::string write;
};
