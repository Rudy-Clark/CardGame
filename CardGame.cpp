// CardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Rudy Clark 2024

#include "Card.h"
#include "Deck.h"

#include <vector>
#include <iostream>

namespace Settings {
    constexpr int dealerStopsAt{ 17 };
    constexpr int bust{ 21 };

    enum GameState {
        LOSE,
        WIN,
        DRAW,
    };
}

struct Player {
    int score{};
};

bool isDraw(Player& player, Player& dealer) {
    return player.score == dealer.score;
}

bool dealerTurn(Deck& deck, Player& dealer, Player& user) {
    while (dealer.score < Settings::dealerStopsAt) {
        Card nextCard{ deck.dealCard() };
        dealer.score += nextCard.getValue();

        std::cout << "The dealer flips a " << nextCard << ".  They now have: " << dealer.score << "\n";
        if (user.score == dealer.score) return true;
    }

    if (dealer.score > Settings::bust) {
        std::cout << "The dealer went bust!" << "\n";
        return false;
    }

    return true;
}

bool userTurn(Deck& deck, Player& user, Player& dealer) {
    char c{};
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> c;
        if (c == 'h') {
            Card card { deck.dealCard() };
            user.score += card.getValue();
            std::cout << "\nYou were dealt " << card << ".  You now have: " << user.score << "\n";
            if (user.score == dealer.score) return true;
        }
        else if (c == 's') {
            break;
        }

        if (user.score > Settings::bust) {
            std::cout << "You went bust! \n";
            return false;
        }
    }

    return true;
}

Settings::GameState playBlackjack()
{
    Deck deck{1};
    deck.shuffle();

    Player dealer{ deck.dealCard().getValue() };

    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player user{ deck.dealCard().getValue() + deck.dealCard().getValue() };

    std::cout << "You have score: " << user.score << '\n';

    if (isDraw(user, dealer)) return Settings::DRAW;

    if (!userTurn(deck, user, dealer)) return Settings::LOSE;

    if (!dealerTurn(deck, dealer, user))
        return Settings::WIN;

    if (isDraw(user, dealer)) return Settings::DRAW;

    return user.score > dealer.score ? Settings::WIN : Settings::LOSE;
}

int main()
{
    /*Card card{ Card::rank_5, Card::suit_heart };

    std::cout << card << '\n';

    for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks)
            std::cout << Card{ rank, suit } << ' ';
    std::cout << '\n';*/

    /*Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';*/

    switch (playBlackjack())
    {
        case(Settings::WIN): {
            std::cout << "You win!" << "\n";
            break;
        }
        case(Settings::LOSE): {
            std::cout << "You lose!" << "\n";
            break;
        }
        default: {
            std::cout << "Draw!" << "\n";
            break;
        }
    }

    return 0;
}