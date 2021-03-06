#include "filesystem.hpp"
#include <string>
#include <sys/stat.h>

bool fileExists(const std::string& name)
{
	struct stat buffer;
	return stat(name.c_str(), &buffer) == 0;
}