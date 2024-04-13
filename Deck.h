#pragma once

#include <string>
#include <array>

#include "Card.h"

class Deck
{
public:
	Deck();
	Deck(int aceValue);

	Card dealCard();
	void shuffle();

private:
	std::array<Card, Card::max_rank * Card::max_suit> m_cards{};
	size_t m_indexPivot{};
};

