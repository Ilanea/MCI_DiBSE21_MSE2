//
// Created by msyu on 23.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "hero.h"

void Sorcerer::attack(Hero &hero, Character &enemy){
    int damage = rand() % ((10 - 5) + 1) + 5 + this->getMagicPower() - hero.getMagicResistance();
    int newHP = hero.getHealthPoints() - damage;
    //cout << "-------------------------------------------------------------------------" << endl;
    //cout << "MagicPower: " << this->getMagicPower(enemy) << endl;
    //cout << "MagicRes: " << hero.getMagicResistance(hero) << endl;
    //cout << "Damage: " << damage << endl;
    hero.setHealthPoints(newHP);
    cout << enemy.getName() << " trifft " << hero.getName() << " mit Magieschaden fuer " << damage << " Lebenspunkte!" << endl;
    //cout << "-------------------------------------------------------------------------" << endl;
}