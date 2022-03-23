//
// Created by msyu on 23.03.2022.
//
#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "fighter.h"

void Fighter::attack(Hero &hero, Character &enemy){
    int damage = 5 + rand() % 10 + getStrenght(hero) - getArmor(enemy);
    enemy.takeDamage(enemy, damage);
    cout << hero.getName(hero) << " trifft " << enemy.getName(enemy) << " fuer " << damage << " Lebenspunkte! - Stärkeschaden" << endl;
}