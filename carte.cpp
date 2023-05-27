#include "carte.hpp"
#include <iostream>

int Card::GetValue() const {
    if (static_cast<int>(rank) > 11)
        return 10;
    return static_cast<int>(rank);  
}

char Card::GetColour() const {
    if (suit == Suit::CLUBS) {
        return 'C';
    } else if (suit == Suit::DIAMONDS) {
        return 'D';
    } else if (suit == Suit::HEARTS) {
        return 'H';
    } else {
        return 'S';
    }
}

bool Card::IsFlipped() const {
    return isFlipped;
}
