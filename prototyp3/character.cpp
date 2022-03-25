//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include "character.h"
#include "hero.h"


using namespace std;

bool Character::checkInventoryItem(const int index){
    if (Inventory[index].getItemValidity()) {
        return true;
    }
    else{
        return false;
    }
}

int Character::addInventoryItem(Item &item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if (!Inventory[i].getItemValidity()) {
            this->Inventory[i].setItemName(item.getItemName());
            this->Inventory[i].setItemGold(item.getItemGold());
            this->Inventory[i].setItemValidity(true);
            cout << "Der Gegenstand \"" << this->Inventory[i].getItemName() << "\" wurde dem Inventar von " << this->getName() << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item Character::removeInventoryItem(int slot){
    if(slot >= 0 && slot <=INVENTORY_SIZE-1){
        if(this->Inventory[slot].getItemValidity()){
            this->Inventory[slot].setItemValidity(false);
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Inventar von " << this->getName() << " entfernt." << endl;
            return this->Inventory[slot];
        }
    }
    return Item();
}

int Character::addEquipmentItem(Item &item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if (!Inventory[i].getItemValidity()) {
            this->Inventory[i].setItemName(item.getItemName());
            this->Inventory[i].setItemGold(item.getItemGold());
            this->Inventory[i].setItemValidity(true);
            this->Inventory[i].setEquipmentItem(true);
            cout << "Der Gegenstand \"" << this->Inventory[i].getItemName() << "\" wurde dem Equipment von " << this->getName() << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item Character::removeEquipmentItem(int slot){
    if(slot >= 0 && slot <=INVENTORY_SIZE-1) {
        if (this->Inventory[slot].getItemValidity() && this->Inventory[slot].getEquipmentItem()) {
            this->Inventory[slot].setItemValidity(false);
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Equipment von "
                 << this->getName() << " entfernt." << endl;
            return this->Inventory[slot];
        }
    }
    return Item();
}