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

    virtual void attack(Hero &hero, Character &enemy) override;

    int getStrenght(){
        return this->Strenght;
    }

};

ostream &operator<<(ostream &out, const Fighter &c);

#endif //PROTOTYP3_FIGHTER_H
