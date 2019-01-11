#include "loadConfig.hpp"
#include <string>
#include <fstream>
#include "json.hpp"
#include "filesystem.hpp"
#include "error.hpp"

nlohmann::json loadJsonFromFile(const std::string& path)
{
	if (!fileExists(path))
		return nlohmann::json();

	std::ifstream file(path);
	nlohmann::json j;
	try
	{
		file >> j;
	}
	catch (const nlohmann::detail::parse_error& e)
	{
        doError("Exception while loading \"" + path + "\" at byte " + std::to_string(e.byte) 
		+ ". Exception details : " + e.what());
	}
	catch (const std::exception& e)
	{
	    doError("Exception while loading \"" + path + "\". Exception details : " + e.what());
	}
	return j;
}

