#include "jucator.hpp"
#include <iostream>
#include <memory>

class Table {
private:
    std::vector<std::unique_ptr<Player>> players;
    int nr_players;
public:
    Table() {nr_players = 0;};
    ~Table() {
        players.clear();
    }
    void StartGame();
    void AddPlayer(char name[20]);
    void ClearPlayers();
    void DisplayPlayers();
    void ClearBotPlayers();
};


void Table::AddPlayer(char name[20]) {
    players.emplace_back(new SplitPlayer(name));
    nr_players++;
}

void Table::ClearBotPlayers() {
    if (players.size() <= 2) {
        std::cout << "There are no additional players to clear." << std::endl;
        return;
    }
    players.erase(players.begin() + 2, players.end());
    nr_players = 2;
    std::cout << "All additional players have been cleared from the table." << std::endl;
}

void Table::ClearPlayers() {
    players.clear();
    nr_players = 0;
    std::cout << "All players have been cleared from the table." << std::endl;
}

void Table::DisplayPlayers() {
    std::cout << "Players currently in the game:" << std::endl;
    
    if (players.empty()) {
        std::cout << "No players at the table." << std::endl;
        return;
    }
    
    for (const auto& player : players) {
        std::cout << "Player name: " << player->GetName() << std::endl;
    }
}

void Table::StartGame() {
    std::cout << "Starting a new game of Blackjack!" << std::endl;
    std::cout << "Please enter your name: ";
    char name[20];
    strcpy(name, "DEALER");
    AddPlayer(name);
    std::cin >> name;
    AddPlayer(name);
    do {
        std::cout << std::endl << "You can:" << std::endl;
        std::cout << "1. Add a bot player." << std::endl;
        std::cout << "2. Clear all players." << std::endl;
        std::cout << "3. Clear all bot players." << std::endl;
        std::cout << "4. Display all players currently in the game." << std::endl;
        std::cout << "5. Start the game." << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            if (nr_players > 5) {
                std::cout << "Too many players" << std::endl;
            } else {
                strcpy(name, "BOT");
                unsigned int j = strlen(name);
                name[j] = '_'; name[j + 1] = (char)(nr_players - 1 + '0'); 
                name[j + 2] = '\0';
                AddPlayer(name);
            }
        } else if (choice == 2) {
            ClearPlayers();
        } else if (choice == 3) {
            ClearBotPlayers();
        } else if (choice == 4) {
            DisplayPlayers();
        } else {
            break;
        }
    } while (true);
    bool add = false; bool split = false;
    do {
        add = false;
        std::cout << "-------------------New Round-------------------" << std::endl;
        for (int i = 0; i < nr_players; i++) {
            Hand& hand = players[i]->GetHand();
            if (i != 1) {
                if (hand.GetNr_cards() == 0) {
                    hand.AddCardToHand(false);
                    add = true;
                } else if (hand.GetTotalValue() <= 16) {
                    hand.AddCardToHand(true);
                    add = true;
                }
                players[i]->Player::DisplayPlayer();
            } else {
                if (hand.GetNr_cards() == 0) {
                    hand.AddCardToHand(true);
                    add = true;
                } else if (hand.GetNr_cards() == 2 && hand.GetLastCard().GetValue() == hand.GetTotalValue() / 2 && split == false) {
                    std::cout << "Hit(H), Pass(P) or Split(S)" << std::endl;
                    char newchoice;
                    std::cin >> newchoice;
                    if (newchoice == 'S') {
                        split = true;
                        add = true;
                        Hand::removeLastCard(hand);
                        Hand& secondHand = players[i]->GetSecondHand();
                        Hand::ClearHand(secondHand);
                        secondHand.AddCardToHand(true);
                    } else if (newchoice == 'H') {
                        hand.AddCardToHand(true);
                        add = true;
                    }
                } else {
                    std::cout << "Hit(H) or Pass(P)" << std::endl;
                    char newchoice;
                    std::cin >> newchoice;
                    if (newchoice == 'H') {
                        hand.AddCardToHand(true);
                        add = true;
                    }
                    if (split == true) {
                        std::cout << "Hit(H) or Pass(P)" << std::endl;
                        std::cin >> newchoice;
                        if (newchoice == 'H') {
                            Hand& secondHand = players[i]->GetSecondHand();
                            secondHand.AddCardToHand(true);
                            add = true;
                        }
                    }
                }
            if (split == true) 
                players[i]->DisplayPlayer();
            else
                players[i]->Player::DisplayPlayer();
            }
        }
    } while (add == true);
    std::cout << "-------------------Result-------------------" << std::endl;
    char winner[20]; 
    strcpy(winner, "DEALER");
    int maxim = 0;
    for (int i = 0; i < nr_players; i++) {
        std::cout << players[i]->GetName() << ":\n";
        Hand& hand = players[i]->GetHand();
        int t = hand.GetTotalValue();
        if (maxim < t && t <= 21) {
            maxim = t;
            strcpy(winner, players[i]->GetName());
        }
        operator<<(std::cout, hand);
        Hand::ClearHand(hand);
        if (i == 1 && split == true) {
            std::cout << "Second hand: \n";
            Hand& secondhand = players[i]->GetSecondHand();
            int t = secondhand.GetTotalValue();
            if (maxim < t && t <= 21) {
                maxim = t;
                strcpy(winner, players[i]->GetName());
            }
            operator<<(std::cout, secondhand);
            Hand::ClearHand(secondhand);
        }
    }
    std::cout << "-------------------WINNER-------------------" << std::endl;
    std::cout << "                   " << winner << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    ClearPlayers();
}
