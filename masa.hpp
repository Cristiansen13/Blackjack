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
