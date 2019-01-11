#pragma once
#include <string>

class Card
{
public:
	virtual bool use();
	virtual std::string getDescription();
};