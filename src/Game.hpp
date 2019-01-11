#pragma once
#include <vector>
#include "Player.hpp"
#include "Deck.hpp"

class Game
{
private:
	Deck deck;
	std::vector<Player> m_players;

public:
	void startGameLoop();
};