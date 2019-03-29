#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;

class Warrior {
public:
    string type;
    int health, damage, cost, win_money, win_point;
    Warrior(string _type, int _health, int _damege, int _cost, int _win_money, int _win_point);
    void info() const;
};

class Infantryman: public Warrior {
public:
    Infantryman();
};

class Archer: public Warrior {
public:
    Archer();
};

class Horseman: public Warrior {
public:
    Horseman();
};

class Mag: public Warrior {
public:
    Mag();
};



class Factory {
public:
    Factory() = default;
    virtual Warrior* createWarrior() = 0;
    virtual ~Factory() {}
};

class InfantryFactory: public Factory {
public:
    Warrior* createWarrior();
};

class ArchersFactory: public Factory {
public:
    Warrior* createWarrior();
};

class CavalryFactory: public Factory {
public:
    Warrior* createWarrior();
};

class MagsFactory: public Factory {
public:
    Warrior* createWarrior();
};


