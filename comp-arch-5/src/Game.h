//
// Created by whiskey on 12/15/21.
//

#ifndef COMP_ARCH_5_GAME_H
#define COMP_ARCH_5_GAME_H


#include "warrior.h"
#include "vector"
#include <mutex>

class Game {
public:
    void go(std::vector<warrior *> &ws);
    static void fight(std::pair<warrior *, warrior *> pair, std::vector<warrior *> &ws);
private:
    static std::vector<std::pair<warrior*, warrior*>>* makePairs(std::vector<warrior *> &ws);
};

#endif //COMP_ARCH_5_GAME_H
