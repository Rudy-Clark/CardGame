#include "Deck.h"
#include "Random.h"
#include <cassert>

Deck::Deck()
{
    size_t index{};
    for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks) {
            m_cards[index] = Card{ rank, suit };
            index++;
        }
}

Deck::Deck(int aceValue) : Deck()
{
    Card::aceValue = aceValue;
}



Card Deck::dealCard()
{
    assert(m_indexPivot <= 51 && "Deck::dealCard ran out of cards");
    return m_cards[m_indexPivot++];
}

void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_indexPivot = 0;
}
