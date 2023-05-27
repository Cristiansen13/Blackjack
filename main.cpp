#include <iostream>
#include <cstdlib>
#include <ctime>
#include "masa.hpp"


int main() {
    Table table;
    char choice;
    do {
        std::cout << "Blackjack Game" << std::endl;
        std::cout << "1. Start a game" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            table.StartGame();
        } else if (choice == '2') {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (true);

    return 0;
}
