//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_HERO_H
#define PROTOTYP3_HERO_H


#include <string.h>
#include "item.h"
#include "character.h"

using namespace std;

class Hero : public Character
{
public:

    using Character::Character;

    //Destruktor
    ~Hero(){

    }

    void attack(Hero &hero, Character &enemy);
    bool fight(Hero &hero, Character &enemy);
    void takeDamage(Hero &hero, const int damage);
    void getAllItems(Hero &hero, Character &enemy);
    void getRandomItem(Hero &hero, Character &enemy);
    void sellAllItems(Hero &hero, int index);
    void sellWonItems(Hero &hero, int index);


};

#endif //PROTOTYP3_HERO_H
