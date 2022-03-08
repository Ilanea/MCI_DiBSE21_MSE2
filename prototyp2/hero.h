//
// Created by msyu on 24.02.2022.
//

#ifndef PROTOTYP_HERO_H
#define PROTOTYP_HERO_H

#include <string.h>
#include "item.h"
#include "character.h"

using namespace std;

class Character;

class Hero
{

private:
    string HeroName;
    int HealthPoints;
    int Gold;
    Item HeroInventory[10];

    void setHeroName(const string newHeroName){
        this->HeroName = newHeroName;
    }

    void setGold(const int newGold){
        this->Gold = newGold;
    }

    void setHealthPoints(const int newHealthPoints){
        this->HealthPoints = newHealthPoints;
    }

public:


    void initHero(const string name, const int hp, const int gold);
    void attack(Hero &hero, Character &enemy);
    bool fight(Hero &hero, Character &enemy);
    void takeDamage(Hero &hero, const int damage);
    int addEquipmentItem(Item &item);
    Item *removeEquipmentItem(int HeroInventorySlot);
    int addInventoryItem(Item &item);
    Item *removeInventoryItem(int HeroInventorySlot);
    void getAllItems(Hero &hero, Character &enemy);
    void getRandomItem(Hero &hero, Character &enemy);
    void sellAllItems(Hero &hero, int index);
    void sellWonItems(Hero &hero, int index);

    string getHeroName(Hero &hero){
        return this->HeroName;
    }

    int getHealthPoints(Hero &hero){
        return this->HealthPoints;
    }

    int getGold(Hero &hero){
        return this->Gold;
    }



};



#endif //PROTOTYP_HERO_H
