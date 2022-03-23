//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_HERO_H
#define PROTOTYP3_HERO_H


#include <cstring>
#include "item.h"
#include "character.h"

using namespace std;

class Hero : public Character
{
public:

    using Character::Character;

    //Destruktor
    ~Hero() {
        cout << "Unsere Heldin " << this->Name << " verabschiedet sich vom Spiel und reitet in den Sonnenuntergang!" << endl;
    }

    bool fight(Hero &hero, Character &enemy);
    void retrieveAllLoot(Hero &hero, Character &enemy);
    void retrieveRandomLoot(Hero &hero, Character &enemy);
    void sellAllItems(Hero &hero, int index);
    void sellLootItems(Hero &hero, int index);


};

#endif //PROTOTYP3_HERO_H
