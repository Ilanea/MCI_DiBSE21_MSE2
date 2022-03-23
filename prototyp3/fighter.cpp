//
// Created by msyu on 23.03.2022.
//
#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

void Fighter::attack(Hero &hero, Character &enemy){
    int damage = 5 + rand() % 10 + getStrenght(enemy) - getArmor(hero);
    int newHP = hero.getHealthPoints(hero) - damage;
    hero.setHealthPoints(newHP);
    cout << hero.getName(hero) << " trifft " << enemy.getName(enemy) << " fuer " << damage << " Lebenspunkte! - Stärkeschaden" << endl;
}