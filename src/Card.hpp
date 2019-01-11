#pragma once
#include <string>

namespace Card
{

enum Type
{
	outOfGas,
	flatTire,
	accident,
	speedLimit,
	stop,
	gasoline,
	spareTire,
	repair,
	endOfLimit,
	roll,
	extraTank,
	punctureProof,
	drivingAce,
	rightOfWay,
	distance25,
	distance50,
	distance75,
	distance200,
	invalid,
};

class Base
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

}