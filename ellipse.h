#pragma once
#include "shape.h"
#include <string>
class line:public shape
{
public:
	line(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export() override;
	virtual std::string get(const std::string &, const std::string & = "") override;
	~line();
private:
	std::string Name;
	std::string write;
};
