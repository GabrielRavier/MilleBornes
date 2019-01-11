#pragma once
#include <vector>
#include "Card.hpp"

class Deck
{
private:
	std::vector<Card *> m_cards;

	void shuffle();
	void makeDeck();
	
public:
	Deck();
	void reset();
};