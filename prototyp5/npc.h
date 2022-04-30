//
// Created by msyu on 23.03.2022.
//

#ifndef PROTOTYP5_NPC_H
#define PROTOTYP5_NPC_H

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
    ~NPC() {
        cout << "Der Gegner " << this->Name << " fiel in ein tiefes Loch und wurde nie wieder gesehen!" << endl;
    }

    void setClass(const int newClass){
        this->Class = newClass;
    }

    int getClass(){
        return this->Class;
    }

};



#endif //PROTOTYP5_NPC_H
