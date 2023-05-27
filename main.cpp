#include <iostream>
#include <cstdlib>
#include <ctime>
#include "masa.hpp"


int main() {
    Table table;
    char choice = '\0';
    do {
        std::cout << "Blackjack Game" << std::endl;
        std::cout << "1. Start a game" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            table.StartGame();
        } else {
            break;
        }

        std::cout << std::endl;
    } while (true);

    return 0;
}
