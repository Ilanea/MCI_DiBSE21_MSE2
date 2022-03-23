//
// Created by msyu on 23.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "sorcerer.h"

void Sorcerer::attack(Hero &hero, Character &enemy){
    int damage = 5 + rand() % 10 + getMagicPower(hero) - getMagicResistance(enemy);
    enemy.takeDamage(enemy, damage);
    cout << hero.getName(hero) << " trifft " << enemy.getName(enemy) << " fuer " << damage << " Lebenspunkte! - Stärkeschaden" << endl;
}