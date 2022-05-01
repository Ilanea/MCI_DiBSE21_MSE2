//
// Created by msyu on 23.03.2022.
//

#ifndef PROTOTYP5_SORCERER_H
#define PROTOTYP5_SORCERER_H

#include <cstring>
#include "npc.h"

class Sorcerer : public NPC
{
protected:
    int MagicPower;

public:

    Sorcerer(const std::string &Name, const int HealthPoints, const int Gold, const int Armor, const int MagicResistance, const int magicpower) :  NPC(Name, HealthPoints, Gold, Armor, MagicResistance), MagicPower(magicpower) {
        setClass(2);
        //std::cout << "Calling Sorcerer::Constructor" << std::endl;
    }

    //Destruktor
    ~Sorcerer()= default;

    virtual void attack(Hero &hero, Character &enemy) override;

    int getMagicPower(){
        return this->MagicPower;
    }

};

std::ostream &operator<<(std::ostream &out, const Sorcerer &c);

#endif //PROTOTYP5_SORCERER_H
