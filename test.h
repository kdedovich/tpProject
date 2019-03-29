#include "soldiery.h"
#include "potion.h"
#include "Player.h"
//здесь должны были быть gtest но я не смогла их нормально подключить к дедлайну, так что пока самописные тесты


void testw(string typ1, int h1, int d1, int c1, int m1, int p1,
           string typ2, int h2, int d2, int c2, int m2, int p2) {
    if (typ1 != typ2)
        cout << "bad type" << "\n";
    if (h1 != h2)
        cout << "bad health" << "\n";
    if (d1 != d2)
        cout << "bad damage" << "\n";
    if (m1 != m2)
        cout << "bad money" << "\n";
    if (c1 != c2)
        cout << "bad cost" << "\n";
    if (p1 != p2)
        cout << "bad point" << "\n";
}

void testp(string typ1, int h1, int d1, int c1, int t1,
           string typ2, int h2, int d2, int c2, int t2) {
    if (typ1 != typ2)
        cout << "bad type" << "\n";
    if (h1 != h2)
        cout << "bad health" << "\n";
    if (d1 != d2)
        cout << "bad damage" << "\n";
    if (t1 != t2)
        cout << "bad time" << "\n";
    if (c1 != c2)
        cout << "bad cost" << "\n";
}

void test_warrior() {
//тестим солдатов
    Warrior w = Warrior("warrior_test", 1, 2, 3, 4, 5);
    testw(w.type, w.health, w.damage, w.cost, w.win_money, w.win_point, "warrior_test", 1, 2, 3, 4, 5);
    Infantryman i = Infantryman();
    testw(i.type, i.health, i.damage, i.cost, i.win_money, i.win_point, "Infantryman", 75, 50, 80, 100, 10);
    Archer a = Archer();
    testw(a.type, a.health, a.damage, a.cost, a.win_money, a.win_point, "Archer", 75, 100, 120, 170, 15);
    Horseman h = Horseman();
    testw(h.type, h.health, h.damage, h.cost, h.win_money, h.win_point, "Horseman", 150, 150, 170, 250, 20);
    Mag m = Mag();
    testw(m.type, m.health, m.damage, m.cost, m.win_money, m.win_point, "Mag", 200, 200, 200, 300, 25);
}

void test_potion() {
    Potion p = Potion("Potion", 1, 2, 3, 4);
    testp(p.type, p.x_health, p.x_damage, p.cost, p.t, "Potion", 1, 2, 3, 4);
    HealthPotion hp = HealthPotion();
    testp(hp.type, hp.x_health, hp.x_damage, hp.cost, hp.t, "HelthPotion", 2, 1, 30, 3);
    DamagePotion dp = DamagePotion();
    testp(dp.type, dp.x_health, dp.x_damage, dp.cost, dp.t, "DamagePotion", 1, 2, 30, 3);
    ComboPotion cp = ComboPotion();
    testp(cp.type, cp.x_health, cp.x_damage, cp.cost, cp.t, "ComboPotion", 2, 2, 50, 5);
}

void test_Factory() {
    InfantryFactory infantry_factory;
    Warrior i = *(infantry_factory.createWarrior());
    ArchersFactory  archers_factory;
    Warrior a = *(archers_factory.createWarrior());
    CavalryFactory  cavalry_factory;
    Warrior h = *(cavalry_factory.createWarrior());
    MagsFactory mags_factory;
    Warrior m = *(mags_factory.createWarrior());
    testw(i.type, i.health, i.damage, i.cost, i.win_money, i.win_point, "Infantryman", 75, 50, 80, 100, 10);
    testw(a.type, a.health, a.damage, a.cost, a.win_money, a.win_point, "Archer", 75, 100, 120, 170, 15);
    testw(h.type, h.health, h.damage, h.cost, h.win_money, h.win_point, "Horseman", 150, 150, 170, 250, 20);
    testw(m.type, m.health, m.damage, m.cost, m.win_money, m.win_point, "Mag", 200, 200, 200, 300, 25);

    HealthPotionFactory health_potion_factory;
    Potion hp = *(health_potion_factory.createPotion());
    DamagePotionFactory damage_potion_factory;
    Potion dp = *(damage_potion_factory.createPotion());
    ComboPotionFactory combo_potion_factory;
    Potion cp = *(combo_potion_factory.createPotion());
    testp(hp.type, hp.x_health, hp.x_damage, hp.cost, hp.t, "HelthPotion", 2, 1, 30, 3);
    testp(dp.type, dp.x_health, dp.x_damage, dp.cost, dp.t, "DamagePotion", 1, 2, 30, 3);
    testp(cp.type, cp.x_health, cp.x_damage, cp.cost, cp.t, "ComboPotion", 2, 2, 50, 5);
}

void test_Player() {
    Player Pl = Player("I");
    Pl.addWarrior("Infantryman");
    Pl.addWarrior("Archer");
    Pl.addWarrior("Horseman");
    Pl.addWarrior("Mag");
    Pl.addPotion("HealthPotion");
    Pl.addPotion("DamagePotion");
    Pl.addPotion("ComboPotion");
    Warrior i = *(Pl.war[0]);
    Warrior a = *(Pl.war[1]);
    Warrior h = *(Pl.war[2]);
    Warrior m = *(Pl.war[3]);
    testw(i.type, i.health, i.damage, i.cost, i.win_money, i.win_point, "Infantryman", 75, 50, 80, 100, 10);
    testw(a.type, a.health, a.damage, a.cost, a.win_money, a.win_point, "Archer", 75, 100, 120, 170, 15);
    testw(h.type, h.health, h.damage, h.cost, h.win_money, h.win_point, "Horseman", 150, 150, 170, 250, 20);
    testw(m.type, m.health, m.damage, m.cost, m.win_money, m.win_point, "Mag", 200, 200, 200, 300, 25);
}

void test() {
    test_warrior();
    test_potion();
    test_Factory();
    cout << "all ok";
}