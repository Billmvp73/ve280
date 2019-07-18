#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>

class Game {
    std::vector<Player *> players;
public:
    const std::vector<Player *> &getPlayers();

    void addPlayer(const std::string &name, Camp camp);

    void run();

    bool isOver() const;

    void printResult() const;

    ~Game();
};

extern Game *getGame();

#endif
