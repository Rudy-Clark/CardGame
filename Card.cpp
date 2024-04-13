#include "Card.h"

int Card::aceValue = 11;

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    static constexpr std::array ranks{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
    static constexpr std::array suits{ 'C', 'D', 'H', 'S' };
    out << ranks[card.rank] << suits[card.suit];

    return out;
}

int Card::getValue() const
{
    static std::array values{ aceValue, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

    return values[rank];
}
