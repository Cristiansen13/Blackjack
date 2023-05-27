#include "jucator.hpp"
#include <iostream>


void Player::Surrender(Hand& hand) {
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