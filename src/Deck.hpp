#pragma once
#include <vector>
#include <memory>
#include "Card.hpp"

class Deck
{
private:
	std::vector<std::unique_ptr<Card::Base>> m_cards;

	void shuffle();
	void makeDeck();
	
public:
	Deck();
	void reset();
};