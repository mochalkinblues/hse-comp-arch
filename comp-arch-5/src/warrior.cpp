//
// Created by whiskey on 12/15/21.
//

#include "warrior.h"

int warrior::getEnergy() const {
    return this->energy_;
}

void warrior::addToEnergy(int value) {
    this->energy_+=value;
}

int warrior::getId() const {
    return this->id_;
}

bool warrior::operator==(const warrior &other) const {
    return id_ == other.getId();
}
