#pragma once
#include <string>
#include <vector>
#include "soldiery.h"
#include "potion.h"
using std::string;
using std::vector;
class Player {
public:
    string name;
    int level, money;
    Player(string _name);
    vector<Warrior*>war;
    vector<Potion*>pot;
    InfantryFactory* infantry_factory;
    ArchersFactory*  archers_factory;
    CavalryFactory*  cavalry_factory;
    MagsFactory* mags_factory;
    HealthPotionFactory* health_potion_factory;
    DamagePotionFactory* damage_potion_factory;
    ComboPotionFactory* combo_potion_factory;
    void addWarrior(string type);
    void addPotion(string type);
    ~Player();
};