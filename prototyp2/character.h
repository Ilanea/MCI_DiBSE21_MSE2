//
// Created by msyu on 24.02.2022.
//

#ifndef PROTOTYP_CHARACTER_H
#define PROTOTYP_CHARACTER_H

#include <string.h>
#include "item.h"
#include "hero.h"

using namespace std;

class Character
{

private:
    string CharacterName;
    int HealthPoints;
    int Gold;
    Item CharacterInventory[10];

    void setCharacterName(const string newCharacterName){
        this->CharacterName = newCharacterName;
    }

    void setHealthPoints(const int newHealthPoints){
        this->HealthPoints = newHealthPoints;
    }

    void setGold(const int newGold){
        this->Gold = newGold;
    }

public:

    void initCharacter(string name, const int hp, const int gold);
    void attack(Character &character, Hero &hero);
    void takeDamage(Character &character, const int damage);
    bool checkInventoryItem(const int index);
    int addInventoryItem(Item &item);
    Item *removeInventoryItem(int CharacterInventorySlot);

    string getCharacterName(const Character &character){
        return this->CharacterName;
    }

    int getHealthPoints(const Character &character){
        return this->HealthPoints;
    }

    int getGold(const Character &character){
        return this->Gold;
    }

    Item *getInventoryItem(int index){
        return &CharacterInventory[index];
    }
};



#endif //PROTOTYP_CHARACTER_H
