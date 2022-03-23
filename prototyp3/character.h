//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_CHARACTER_H
#define PROTOTYP3_CHARACTER_H

#include <string.h>
#include "item.h"
//#include "hero.h"


using namespace std;

class Hero;

class Character
{

private:
    string Name;
    int HealthPoints;
    int Gold;
    int Armor;
    int MagicResistance;


protected:
    Item Inventory[10];

    void setName(const string newName){
        this->Name = newName;
    }

    void setHealthPoints(const int newHealthPoints){
        this->HealthPoints = newHealthPoints;
    }

    void setGold(const int newGold){
        this->Gold = newGold;
    }

public:

    //Konstruktor
    Character(const string &name, const int hp, const int gold) : Name(name), HealthPoints(hp), Gold(gold) {
        cout << "Calling Character::Constructor" << std::endl;
    }

    //Destruktor
    ~Character(){

    }

    void attack(Character &character, Hero &hero);
    void takeDamage(Character &character, const int damage);
    bool checkInventoryItem(const int index);
    int addInventoryItem(Item &item);
    Item removeInventoryItem(int CharacterInventorySlot);
    int addEquipmentItem(Item &item);
    Item removeEquipmentItem(int InventorySlot);

    string getName(const Character &character){
        return this->Name;
    }

    int getHealthPoints(const Character &character){
        return this->HealthPoints;
    }

    int getGold(const Character &character){
        return this->Gold;
    }

    Item *getInventoryItem(int index){
        return &Inventory[index];
    }
};


#endif //PROTOTYP3_CHARACTER_H
