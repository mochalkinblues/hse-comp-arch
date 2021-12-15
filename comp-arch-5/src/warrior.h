//
// Created by whiskey on 12/15/21.
//

#ifndef COMP_ARCH_5_WARRIOR_H
#define COMP_ARCH_5_WARRIOR_H

class warrior {
public:
    int getEnergy() const;
    int getId() const;
    void addToEnergy(int value);
    explicit warrior(int energy, int id) {
        this->energy_ = energy;
        this->id_ = id;
    }
    bool operator==(const warrior &other) const;
private:
    int energy_;
    int id_;
};


#endif //COMP_ARCH_5_WARRIOR_H
