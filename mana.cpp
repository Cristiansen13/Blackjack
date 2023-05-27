#include <iostream>
#include <vector>
#include "mana.hpp"

int Hand::GetTotalValue() const {
    int sum = 0;
    if (cards.empty()) {
        return sum;
    }
    for (int i = 0; i < nr_cards; i++) {
        sum += cards[i]->GetValue();   
    }
    return sum;
}

void Hand::Display() const {
    for (int i = 0; i < nr_cards; i++) {
        std::cout << i << ". ";
        if (cards[i]->IsFlipped() == false) {
            std::cout << "UnknownCard" << std::endl;
        } else {
            std::cout << cards[i]->GetValue() << ' ';
            std::cout << cards[i]->GetColour() << std::endl;
        }
    }
}

void Hand::AddCardToHand(bool isFlipped) {
    cards.push_back(new Card(isFlipped));
    nr_cards++;
}

void Hand::ClearHand(Hand& hand) {
    for (int i = 0; i < hand.nr_cards; i++) {
        delete hand.cards[i];
    }
    hand.cards.clear();
    hand.nr_cards = 0;
    std::cout << "All cards have been cleared from the table." << std::endl;
}
