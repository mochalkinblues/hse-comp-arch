#include <iostream>
#include "warrior.h"
#include "Game.h"
#include <vector>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }

    std::vector<warrior*> warriors;

    for (int i = 1; i < argc; ++i) {
        warriors.emplace_back(
                new warrior(
                strtol(argv[i], nullptr, 10), i
                )
        );
    }

    Game g;
    g.go(warriors);

    std::cout << "winner: Warrior {id: " << warriors[0]->getId() << ", energy: " << warriors[0]->getEnergy() << "}";
}