#pragma once
#include <string>

class Card
{
private:
	std::string m_description;

public:
	virtual bool use();
	std::string getDescription()
	{
		return m_description;
	};
};