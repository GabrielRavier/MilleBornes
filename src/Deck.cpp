#include "Deck.hpp"
#include <algorithm>
#include "random.hpp"

Deck::Deck()
{
	this->reset();
}

void Deck::shuffle()
{
	std::shuffle(m_cards.begin(), m_cards.end(), ravier::engine);
}

void Deck::makeDeck()
{

}

void Deck::reset()
{
	this->makeDeck();
	this->shuffle();
}