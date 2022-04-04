//
// Created by msyu on 23.03.2022.
//

#ifndef PROTOTYP3_SORCERER_H
#define PROTOTYP3_SORCERER_H

#include <cstring>
#include "npc.h"

using namespace std;

class Sorcerer : public NPC
{
protected:
    int MagicPower;

public:

    Sorcerer(const string &Name, const int HealthPoints, const int Gold, const int Armor, const int MagicResistance, const int magicpower) :  NPC(Name, HealthPoints, Gold, Armor, MagicResistance), MagicPower(magicpower) {
        setClass(2);
        cout << "Calling Sorcerer::Constructor" << std::endl;
    }

    //Destruktor
    ~Sorcerer()= default;

    virtual void attack(Hero &hero, Character &enemy) override;

    int getMagicPower(){
        return this->MagicPower;
    }

};

ostream &operator<<(ostream &out, const Sorcerer &c);

#endif //PROTOTYP3_SORCERER_H
