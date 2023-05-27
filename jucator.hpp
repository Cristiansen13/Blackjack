#include "mana.hpp"
#include <cstring>
#include <iostream>

class Player {
protected:
    Hand hand;
    char name[20]{};
public:
    explicit Player(const char nume[20]) {
        strcpy(name, nume);
        hand = Hand();
    };
    Player& operator=(const Player& other) {
        if (this == &other)
            return *this;
        hand = other.hand;
        strcpy(name, other.name);
        return *this;
    }
    static void Surrender(Hand& hand);
    char *GetName() {
        return name;
    };
    Hand& GetHand() {
        return hand;
    }
    virtual Hand& GetSecondHand() = 0;
    virtual void DisplayPlayer();
};

class SplitPlayer : public Player {
private:
    Hand secondHand;
public:
    explicit SplitPlayer(const char nume[20]) : Player(nume) {
        secondHand = Hand();
    }
    Hand& GetSecondHand() override{
        return secondHand;
    }
    void DisplayPlayer() override;
};
