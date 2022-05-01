//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP5_CHARACTER_H
#define PROTOTYP5_CHARACTER_H

#include <cstring>
#include "item.h"
#include "exception.h"
#include <vector>
#include <memory>

class Hero;

class Character
{

protected:
    std::string Name;
    int HealthPoints;
    int Gold;
    int Armor;
    int MagicResistance;
    std::vector<std::shared_ptr<Item>> Inventory;

    void setGold(const int newGold){
        if(newGold < 0){
            throw InvalidGoldException("Character::setGold(): Gold cannot be a negative value.");
        }
        else{
            this->Gold = newGold;
        }
    }

public:

    int InventoryCount=0;

    //Konstruktor
    Character(const std::string &name, const int hp, const int gold, const int armor, const int magicresistance) : Name(name), HealthPoints(hp), Gold(gold), Armor(armor), MagicResistance(magicresistance), Inventory() {

        if(name.empty() || hp < 0 || gold < 0){
            throw InvalidConstructorException("Character::Constructor: Name cannot be empty, HP and Gold cannot have negative value.");
        }

        //cout << "Calling Character::Constructor" << std::endl;
    }

    //Destruktor
    virtual ~Character()= default;

    virtual void attack(Hero &hero, Character &enemy) = 0;
    int addInventoryItem(std::shared_ptr<Item> item);
    Item removeInventoryItem(int CharacterInventorySlot);
    int addEquipmentItem(std::shared_ptr<Item> item);
    Item removeEquipmentItem(int InventorySlot);

    std::string getName(){
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

    std::shared_ptr<Item> *getInventoryItem(int index){
        if(index < 0 && index > InventoryCount){
            throw InventoryOutOfRange("Character::getInventoryItem: Inventory Check out of Range of Inventory Size.");
        }
        else{
            return &Inventory.at(index);
        }
    }
};

#endif //PROTOTYP5_CHARACTER_H
