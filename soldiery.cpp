
#include <iostream>
#include <vector>
#include <string>
#include "soldiery.h"
using std::cout;
using std::vector;
using std::string;

Warrior::Warrior(string _type, int _health, int _damage, int _cost, int _win_money, int _win_point) :
        type(_type), health(_health), damage(_damage), cost(_cost), win_money(_win_money), win_point(_win_point)
{}

void Warrior::info() const {
    cout << "type: " << type << "\n";
    cout << "health: " << health << "\n";
    cout << "damage:  " << damage << "\n";
    cout << "coat: " << cost << "\n";
    cout << "win money: " << win_money << "\n";
    cout << "win point: " << win_point << "\n";
}

Infantryman::Infantryman() :
        Warrior("Infantryman", 75, 50, 80, 100, 10)
{}


Archer::Archer() :
        Warrior("Archer", 75, 100, 120, 170, 15)
{}

Horseman::Horseman() :
        Warrior("Horseman", 150, 150, 170, 250, 20)
{}


Mag::Mag() :
        Warrior("Mag", 200, 200, 200, 300, 25)
{}


Warrior* ArchersFactory::createWarrior() {
    return new Archer();
}

Warrior* CavalryFactory::createWarrior() {
    return new Horseman();
}

Warrior* MagsFactory::createWarrior() {
    return new Mag();
}

Warrior* InfantryFactory::createWarrior() {
    return new Infantryman();
}