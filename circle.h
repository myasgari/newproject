#pragma once
#include "shape.h"
#include <string>
class circle :public shape
{
public:
	circle(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export() override ;
	virtual std::string get(const std::string &) override;
	~circle();
private:
	std::string Name;
	std::string write;
};
