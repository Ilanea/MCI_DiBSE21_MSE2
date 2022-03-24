//
// Created by msyu on 23.03.2022.
//
#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

void Fighter::attack(Hero &hero, Character &enemy){
    int damage = rand() % ((10 - 5) + 1) + 5 + this->getStrenght(enemy) - hero.getArmor(hero);
    int newHP = hero.getHealthPoints(hero) - damage;
    //cout << "-------------------------------------------------------------------------" << endl;
    //cout << "Strenght: " << this->getStrenght(enemy) << endl;
    //cout << "Armor: " << hero.getArmor(hero) << endl;
    //cout << "Damage: " << damage << endl;
    hero.setHealthPoints(newHP);
    cout << enemy.getName(enemy) << " trifft " << hero.getName(hero) << " mit Staerkeschaden fuer " << damage << " Lebenspunkte!" << endl;
    //cout << "-------------------------------------------------------------------------" << endl;
}