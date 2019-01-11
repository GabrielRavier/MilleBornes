#include "log.hpp"
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include "filesystem.hpp"

static std::fstream logFile;

const std::string logFileName = "MilleBornes.log";

void initLogFile()
{
    if (fileExists(logFileName))
    {
        logFile.open(logFileName, std::fstream::app);
        logFile << "\n\n";
    }
    else
        logFile.open(logFileName, std::fstream::out);

    const auto now = time(nullptr);
    logFile << "New session started at : " << std::put_time(localtime(&now), "%c") << std::endl;
}

void logDebug(const std::string& str)
{
    const auto now = time(nullptr);
    logFile << '<' << std::put_time(localtime(&now), "%c") << '>' << " : Debug : " << str << std::endl;
}

void logInfo(const std::string& str)
{
    const auto now = time(nullptr);
    logFile << '<' << std::put_time(localtime(&now), "%c") << '>' << " : Information : " << str << std::endl;
}

void logWarning(const std::string& str)
{
    const auto now = time(nullptr);
    logFile << '<' << std::put_time(localtime(&now), "%c") << '>' << " : Warning : " << str << std::endl;
}

void logError(const std::string& str)
{
    const auto now = time(nullptr);
    logFile << '<' << std::put_time(localtime(&now), "%c") << '>' << " : Error : " << str << std::endl;
}
