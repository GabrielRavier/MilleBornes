#include "error.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

[[noreturn]] void doError(const std::string& errMsg)
{
	std::cerr << errMsg;
	exit(EXIT_FAILURE);
}
