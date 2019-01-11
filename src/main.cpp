#include <vector>
#include <string>
#include "Game.hpp"

int main(int argc, char *argv[])
{
	std::vector<std::string> args(argv, argv + argc);

	Game game;
	game.startGameLoop();

	return 0;
}