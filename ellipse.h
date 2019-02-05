#pragma once
#pragma once
#include "shape.h"
#include <string>
class ellipse :public shape
{
public:
	ellipse(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export() override;
	virtual std::string get(const std::string &) override;
	~ellipse();
private:
	std::string Name;
	std::string write;
};
