#include "Player.h"

Player::Player(string _name):
        name(_name), level(0), money(1000){
    InfantryFactory* infantry_factory = new InfantryFactory;
    ArchersFactory*  archers_factory  = new ArchersFactory;
    CavalryFactory*  cavalry_factory  = new CavalryFactory;
    MagsFactory* mags_factory = new MagsFactory;
    HealthPotionFactory* health_potion_factory = new HealthPotionFactory;
    DamagePotionFactory* damage_potion_factory = new DamagePotionFactory;
    ComboPotionFactory* combo_potion_factory = new ComboPotionFactory;
}


void Player::addWarrior(string type) {
    if (type == "Infantryman")
        war.push_back(infantry_factory->createWarrior());
    if (type == "Horseman")
        war.push_back(cavalry_factory->createWarrior());
    if (type == "Archer")
        war.push_back(archers_factory->createWarrior());
    if (type == "Mag")
        war.push_back(mags_factory->createWarrior());
}

void Player::addPotion(string type) {
    if (type == "HealthPotion")
        pot.push_back(health_potion_factory->createPotion());
    if (type == "DamagePotion")
        pot.push_back(damage_potion_factory->createPotion());
    if (type == "ComboPotion")
        pot.push_back(combo_potion_factory->createPotion());
}

Player::~Player() {
    delete infantry_factory;
    delete archers_factory;
    delete cavalry_factory;
    delete mags_factory;
    delete health_potion_factory;
    delete damage_potion_factory;
    delete combo_potion_factory;
    for (auto w : war)
        delete w;
    for (auto p : pot)
        delete p;
    war.clear();
    pot.clear();
}