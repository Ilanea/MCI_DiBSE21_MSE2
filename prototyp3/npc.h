//
// Created by msyu on 23.03.2022.
//

#ifndef PROTOTYP3_NPC_H
#define PROTOTYP3_NPC_H

#include <cstring>
#include "character.h"

using namespace std;

class NPC : public Character
{
protected:
    // Class:
    // 1: Fighter
    // 2: Sorcerer
    int Class=0;
public:

    using Character::Character;

    //Destruktor
    ~NPC()= default;

    void setClass(const int newClass){
        this->Class = newClass;
    }

};

#endif //PROTOTYP3_NPC_H
