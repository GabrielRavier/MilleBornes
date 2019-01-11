#pragma once
#include "json.hpp"
#include <string>

nlohmann::json loadJsonFromFile(const std::string& path);

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