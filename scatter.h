#pragma once
#include "shape.h"
#include <string>
class scatter :public shape
{
public:
	scatter(const std::string &);
	virtual std::string returnName() override;
	virtual std::string Export(std::vector<shape *>&) override;
	virtual std::string get(const std::string &, const std::string & = "") override;
	~scatter();
private:
	std::string Name;
	std::string write;
};
