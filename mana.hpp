#include <vector>
#include "carte.hpp"
#include <memory>
#include <iostream>

class Hand {
private:
    std::vector<Card*> cards;
    int nr_cards;
public:
    Hand() { nr_cards = 0; };
    friend std::ostream& operator<<(std::ostream& os, const Hand& hand) {
        for (int i = 0; i < hand.nr_cards; i++) {
            os << i << ". ";
            os << hand.cards[i]->GetValue() << ' ';
            os << hand.cards[i]->GetColour() << std::endl;
        }
        return os;
    };
    Hand& operator=(const Hand& other) { 
        if(this == &other) 
            return *this;
        for (auto card : cards)
            delete card;
        cards.clear();
        for (int i = 0; i < other.nr_cards; i++)
            cards.push_back(new Card(*other.cards[i]));
        nr_cards = other.nr_cards;
        return *this;
    }
    ~Hand() {
        for (auto card : cards)
            delete card;
        cards.clear();
    }
    void AddCardToHand(bool isFlipped);
    int GetTotalValue() const;
    void Display() const;
    static void ClearHand(Hand& hand);
    int GetNr_cards() const {
        return nr_cards;
    };
    Card& GetLastCard (){
        return *cards.back();
    };
    static void removeLastCard(Hand& hand) {
        delete hand.cards.back();
        hand.cards.pop_back();
        hand.nr_cards--;
    };
};
