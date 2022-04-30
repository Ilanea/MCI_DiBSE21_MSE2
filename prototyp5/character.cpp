//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include "character.h"
#include "hero.h"


using namespace std;

int Character::addInventoryItem(Item *item){
    this->Inventory.push_back(*item);
    cout << "Der Gegenstand \"" << this->Inventory.back().getItemName() << "\" wurde dem Inventar von " << this->getName() << " hinzugefuegt." << endl;
    return InventoryCount++;
}

Item Character::removeInventoryItem(int slot){
    if(slot >= 0 && slot <= InventoryCount){
        if(!Inventory.empty()){
            auto retval = Inventory[slot];
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Inventar von " << this->getName() << " entfernt." << endl;
            this->Inventory.erase(Inventory.begin()+slot);
            this->InventoryCount--;
            return retval;
        }
        else{
            throw InvalidItemException("Character::removeInventoryItem(): Inventory Empty");
        }
    }
    throw InvalidItemException("Character::removeInventoryItem(): Invalid item");
}

int Character::addEquipmentItem(Item *item){
    this->Inventory.push_back(*item);
    this->Inventory.back().setEquipmentItem(true);
    cout << "Der Gegenstand \"" << this->Inventory.back().getItemName() << "\" wurde dem Equipment von " << this->getName() << " hinzugefuegt." << endl;
    return InventoryCount++;
}

Item Character::removeEquipmentItem(int slot){
    if(slot >= 0 && slot <=Inventory.size()) {
        if (this->Inventory[slot].getEquipmentItem()) {
            auto retval = Inventory[slot];
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Equipment von " << this->getName() << " entfernt." << endl;
            Inventory.erase(Inventory.begin()+slot);
            return retval;
        }
    }
    throw InvalidItemException("Character::removeEquipmentItem(): Invalid item");
}