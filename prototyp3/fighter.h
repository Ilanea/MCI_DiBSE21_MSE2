//
// Created by msyu on 23.03.2022.
//

#ifndef PROTOTYP3_FIGHTER_H
#define PROTOTYP3_FIGHTER_H

#include <cstring>
#include "npc.h"

using namespace std;

class Fighter : public NPC
{
protected:
    int Strenght;

public:

    Fighter(const string &Name, const int HealthPoints, const int Gold, const int Armor, const int MagicResistance, const int strenght) :  NPC(Name, HealthPoints, Gold, Armor, MagicResistance), Strenght(strenght) {
        setClass(1);
        cout << "Calling Fighter::Constructor" << std::endl;
    }

    //Destruktor
    ~Fighter()= default;

    void attack(Hero &hero, Character &enemy);

    int getStrenght(const Character &character){
        return this->Strenght;
    }

};

#endif //PROTOTYP3_FIGHTER_H
