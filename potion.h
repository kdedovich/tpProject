#pragma once
#include <string>
using std::string;

class Potion {
public:
    string type;
    int x_health, x_damage, cost, t;
    Potion(string _type, int _health, int _damege, int _cost, int _t);
    void info() const;
};

class HealthPotion: public Potion {
public:
    HealthPotion();
};

class DamagePotion: public Potion {
public:
    DamagePotion();
};

class ComboPotion: public Potion{
public:
    ComboPotion();
};


class PotionFactory {
public:
    virtual Potion* createPotion() = 0;
    virtual ~PotionFactory() {}
};

class HealthPotionFactory: public PotionFactory {
public:
    Potion* createPotion();
};

class DamagePotionFactory: public PotionFactory {
public:
    Potion* createPotion();
};

class ComboPotionFactory: public PotionFactory {
public:
    Potion* createPotion();
};



