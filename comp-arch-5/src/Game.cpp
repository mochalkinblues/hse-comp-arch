//
// Created by whiskey on 12/15/21.
//

#include "Game.h"
#include "warrior.h"
#include <vector>
#include <mutex>
#include <algorithm>
#include <random>
#include <thread>
#include <iostream>

void Game::fight(std::pair<warrior*, warrior*> pair, std::vector<warrior*> &ws) {

    auto *first = pair.first;
    auto *second = pair.second;

    if (first->getEnergy() > second->getEnergy()) {
        first->addToEnergy(second->getEnergy());
        ws.erase(std::find(ws.begin(), ws.end(), second));
    } else {
        second->addToEnergy(first->getEnergy());
        ws.erase(std::find(ws.begin(), ws.end(), first));
    }

}


void Game::go(std::vector<warrior*> &ws) {
    while (ws.size() != 1) {
        auto pairs = makePairs(ws);

        auto *threads = new std::thread[pairs->size()];
        for (int i = 0; i < pairs->size(); ++i) {
            if ((*pairs)[i].first->getId() == (*pairs)[i].second->getId()) {
                (*pairs)[i].first->addToEnergy((*pairs)[i].first->getEnergy());
                continue;
            }

            threads[i] = std::thread(Game::fight, (*pairs)[i], std::ref(ws));
        }

        for (int i = 0; i < pairs->size(); ++i) {
            try {
                threads[i].join();
            } catch (...) {
            }
        }
    }
}

std::vector<std::pair<warrior*, warrior*>>* Game::makePairs(std::vector<warrior*> &ws) {
    auto *pairs = new std::vector<std::pair<warrior*, warrior*>>();

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(ws.begin(), ws.end(), std::default_random_engine(seed));

    for (int i = 0; i < ws.size(); i+=2) {
        if (i == ws.size() - 1 && ws.size() % 2 == 1) {
            std::pair<warrior*, warrior*> pair = std::make_pair(ws[i], ws[i]);
            pairs->push_back(pair);
        } else {
            pairs->emplace_back(ws[i], ws[i + 1]);
        }
    }

    return pairs;
}
