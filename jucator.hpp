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
    virtual ~Player() = 0;
    static void Surrender(const Hand& hand);
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
    ~SplitPlayer() override = default;
    explicit SplitPlayer(const char nume[20]) : Player(nume), secondHand() {}
    Hand& GetSecondHand() override{
        return secondHand;
    }
    void DisplayPlayer() override;
};



void Player::Surrender(const Hand& hand) {
    if (hand.GetTotalValue() > 21)
        std::cout << "S ";
}

void Player::DisplayPlayer() {
    Surrender(hand);
    std::cout << name << ":\n";
    hand.Display();
}

void SplitPlayer::DisplayPlayer() {
    std::cout << name << ":\n";
    Surrender(hand);
    std::cout << "First hand: \n";
    hand.Display();
    Surrender(secondHand);
    std::cout << "Second hand: \n";
    secondHand.Display();
}

Player::~Player() = default;