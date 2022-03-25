//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_CHARACTER_H
#define PROTOTYP3_CHARACTER_H

#include <cstring>
#include "item.h"


#define INVENTORY_SIZE  10

using namespace std;

class Hero;

class Character
{

protected:
    string Name;
    int HealthPoints;
    int Gold;
    int Armor;
    int MagicResistance;
    Item Inventory[INVENTORY_SIZE] = {};

    void setName(const string &newName){
        this->Name = newName;
    }

    void setGold(const int newGold){
        this->Gold = newGold;
    }


public:

    //Konstruktor
    Character(const string &name, const int hp, const int gold, const int armor, const int magicresistance) : Name(name), HealthPoints(hp), Gold(gold), Armor(armor), MagicResistance(magicresistance), Inventory() {
        cout << "Calling Character::Constructor" << std::endl;
    }

    //Destruktor
    virtual ~Character()= default;

    virtual void attack(Hero &hero, Character &enemy) = 0;
    bool checkInventoryItem(const int index);
    int addInventoryItem(Item &item);
    Item removeInventoryItem(int CharacterInventorySlot);
    int addEquipmentItem(Item &item);
    Item removeEquipmentItem(int InventorySlot);

    string getName(){
        return this->Name;
    }

    int getHealthPoints(){
        return this->HealthPoints;
    }

    void setHealthPoints(const int newHealthPoints){
        this->HealthPoints = newHealthPoints;
    }

    int getGold(){
        return this->Gold;
    }

    int getArmor(){
        return this->Armor;
    }

    int getMagicResistance(){
        return this->MagicResistance;
    }

    Item *getInventoryItem(int index){
        return &Inventory[index];
    }
};

#endif //PROTOTYP3_CHARACTER_H
