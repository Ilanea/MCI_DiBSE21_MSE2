//
// Created by msyu on 23.03.2022.
//
#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

void Fighter::attack(Hero &hero, Character &enemy){
    int damage = rand() % ((10 - 5) + 1) + 5 + this->getStrenght() - hero.getArmor();
    int newHP = hero.getHealthPoints() - damage;
    //cout << "-------------------------------------------------------------------------" << endl;
    //cout << "Strenght: " << this->getStrenght(enemy) << endl;
    //cout << "Armor: " << hero.getArmor(hero) << endl;
    //cout << "Damage: " << damage << endl;
    hero.setHealthPoints(newHP);
    std::cout << enemy.getName() << " trifft " << hero.getName() << " mit Staerkeschaden fuer " << damage << " Lebenspunkte!" << std::endl;
    //cout << "-------------------------------------------------------------------------" << endl;
}