#include <iostream>
#include <vector>
#include "potion.h"
using std::cout;
using std::vector;
using std::string;

Potion::Potion(string _type, int _health, int _damage, int _cost, int _t) :
        type(_type), x_health(_health), x_damage(_damage), cost(_cost), t(_t)
{}

void Potion::info() const {
    cout << "type: " << type << "\n";
    cout << "health: " << x_health << "\n";
    cout << "damage:  " << x_damage << "\n";
    cout << "cost: " << cost << "\n";
    cout << "time: " << t << "\n";
}

HealthPotion::HealthPotion() :
        Potion("HelthPotion", 2, 1, 30, 3)
{}


DamagePotion::DamagePotion() :
        Potion("DamagePotion", 1, 2, 30, 3)
{}

ComboPotion::ComboPotion() :
        Potion("ComboPotion", 2, 2, 50, 5)
{}


Potion* HealthPotionFactory::createPotion() {
    return new HealthPotion();
}

Potion* DamagePotionFactory::createPotion() {
    return new DamagePotion();
}

Potion* ComboPotionFactory::createPotion() {
    return new ComboPotion();
}