//
// Created by msyu on 23.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "hero.h"

void Sorcerer::attack(Hero &hero, Character &enemy){
    int damage = 5 + rand() % 10 + getMagicPower(enemy) - getMagicResistance(hero);
    int newHP = hero.getHealthPoints(hero) - damage;
    hero.setHealthPoints(newHP);
    cout << enemy.getName(enemy) << " trifft " << hero.getName(hero) << " mit Magieschaden fuer " << damage << " Lebenspunkte!" << endl;
}