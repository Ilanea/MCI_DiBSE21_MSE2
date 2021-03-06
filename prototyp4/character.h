//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_CHARACTER_H
#define PROTOTYP3_CHARACTER_H

#include <cstring>
#include "item.h"
#include "exception.h"


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
    Item *Inventory[INVENTORY_SIZE] = {};

    void setGold(const int newGold){
        if(newGold < 0){
            throw InvalidGoldException("Character::setGold(): Gold cannot be a negative value.");
        }
        else{
            this->Gold = newGold;
        }
    }

public:

    //Konstruktor
    Character(const string &name, const int hp, const int gold, const int armor, const int magicresistance) : Name(name), HealthPoints(hp), Gold(gold), Armor(armor), MagicResistance(magicresistance), Inventory() {

        if(name.empty() || hp < 0 || gold < 0){
            throw InvalidConstructorException("Character::Constructor: Name cannot be empty, HP and Gold cannot have negative value.");
        }

        cout << "Calling Character::Constructor" << std::endl;
    }

    //Destruktor
    virtual ~Character()= default;

    virtual void attack(Hero &hero, Character &enemy) = 0;
    bool checkInventoryItem(const int index);
    int addInventoryItem(Item *item);
    Item *removeInventoryItem(int CharacterInventorySlot);
    int addEquipmentItem(Item *item);
    Item *removeEquipmentItem(int InventorySlot);

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
        if(index < 0 && index > INVENTORY_SIZE){
            throw InventoryOutOfRange("Character::getInventoryItem: Inventory Check out of Range of Inventory Size.");
        }
        else{
            return Inventory[index];
        }
    }
};

#endif //PROTOTYP3_CHARACTER_H
