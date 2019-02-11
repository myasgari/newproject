#pragma once
#include "shape.h"
#include <string>
class polyline :public shape
{
public:
	polyline(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export() override;
	virtual std::string get(const std::string &, const std::string & = "") override;
	~polyline();
private:
	std::string Name;
	std::string write;
};
