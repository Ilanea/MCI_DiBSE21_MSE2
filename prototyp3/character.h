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

    void setHealthPoints(const int newHealthPoints){
        this->HealthPoints = newHealthPoints;
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
    ~Character()= default;

    void attack(Hero &hero, Character &enemy);
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

    int getArmor(const Character &character){
        return this->Armor;
    }

    int getMagicResistance(const Character &character){
        return this->MagicResistance;
    }

    Item *getInventoryItem(int index){
        return &Inventory[index];
    }
};


#endif //PROTOTYP3_CHARACTER_H
