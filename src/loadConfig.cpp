#include "loadConfig.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "json.hpp"
#include "filesystem.hpp"
#include "error.hpp"
#include "log.hpp"	

using namespace std::string_literals;

nlohmann::json fileToJson(const std::string& path)
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

#if __cplusplus >= 201703L
template<typename T> void safeGet(const nlohmann::json& j, const std::string& name, T& varTbc)
{
	if constexpr(std::is_same_v<T, std::string>)
	{
		if (j[name].is_string())
			varTbc = j[name];
	}
	else if constexpr(std::is_same_v<T, bool>)
    {
        if (j[name].is_boolean())
            varTbc = j[name];
    }
    else if constexpr(std::numeric_limits<T>::is_integer)
    {
        if (j[name].is_number())
            varTbc = j[name];
    }
    else
        static_assert(std::is_same_v<T, void>, "This type is not supported");   // Best I can think of right now. There are probably better ways, but this works I suppose
}
#else
// C++11-friendly replacement
void safeGet(const nlohmann::json& j, const std::string& name, string& varTbc)
{
    if (j[name].is_string())
        varTbc = j[name];
}

void safeGet(const json& j, const string& name, bool& varTbc)
{
    if (j[name].is_boolean())
        varTbc = j[name];
}

void safeGet(const json& j, const string& name, int& varTbc)
{
    if (j[name].is_number())
        varTbc = j[name];
}
#endif

std::vector<int> g_cardsNumbers;
std::vector<std::string> g_cardsDescriptions;

constexpr const char *CONFIG_ATTRIBUTES_NAMES[] = 
{
	"outOfGas",
	"flatTire",
	"accident",
	"speedLimit",
	"stop",
	"gasoline",
	"spareTire",
	"repair",
	"endOfLimit",
	"roll",
	"extraTank",
	"punctureProof",
	"drivingAce",
	"rightOfWay",
	"distance25",
	"distance50",
	"distance75",
	"distance100",
	"distance200",
};

void loadConfig()
{
	const std::string CONFIG_FILE_NAME = "config.json";
	try
	{
		auto config = fileToJson(CONFIG_FILE_NAME);
		for (auto currentAttr : CONFIG_ATTRIBUTES_NAMES)
		{
			int amount = 0;
			safeGet(config, currentAttr, amount);
			if (amount == 0)
				logWarning("Missing amount of cards for : "s + currentAttr);
			g_cardsNumbers.push_back(amount);
		}

		for (auto currentAttr : CONFIG_ATTRIBUTES_NAMES)
		{
			std::string description = "MISSING DESCRIPTION";
			safeGet(config, currentAttr, description);
			if (description == "MISSING DESCRIPTION")
				logWarning("Missing description for : "s + currentAttr);
			g_cardsDescriptions.push_back(description);
		}
	}
	catch (const nlohmann::detail::parse_error& e)
	{
        doError("Exception while loading \"" + CONFIG_FILE_NAME + "\" at byte " + std::to_string(e.byte) 
		+ ". Exception details : " + e.what());
	}
	catch (const std::exception& e)
	{
	    doError("Exception while loading \"" + CONFIG_FILE_NAME + "\". Exception details : " + e.what());
	}
}