//
// Created by msyu on 23.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "hero.h"

void Sorcerer::attack(Hero &hero, Character &enemy){
    int damage = rand() % ((10 - 5) + 1) + 5 + this->getMagicPower(enemy) - hero.getMagicResistance(hero);
    int newHP = hero.getHealthPoints(hero) - damage;
    //cout << "-------------------------------------------------------------------------" << endl;
    //cout << "MagicPower: " << this->getMagicPower(enemy) << endl;
    //cout << "MagicRes: " << hero.getMagicResistance(hero) << endl;
    //cout << "Damage: " << damage << endl;
    hero.setHealthPoints(newHP);
    cout << enemy.getName(enemy) << " trifft " << hero.getName(hero) << " mit Magieschaden fuer " << damage << " Lebenspunkte!" << endl;
    //cout << "-------------------------------------------------------------------------" << endl;
}