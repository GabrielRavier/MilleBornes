#include <vector>
#include <string>
#include "Game.hpp"
#include "error.hpp"
#include "loadConfig.hpp"
#include "log.hpp"

using namespace std::string_literals;

void init()
{
	loadConfig();
	initLogFile();
}

int main(int argc, char *argv[])
{
	try
	{
		std::vector<std::string> args(argv, argv + argc);

		init();

		Game game;
		game.startGameLoop();
	}
	catch (std::exception& e)
	{
		doError("Exception occured. Exception details : "s + e.what());
	}

	return 0;
}