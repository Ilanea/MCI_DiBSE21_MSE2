//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include "character.h"
#include "hero.h"


using namespace std;

bool Character::checkInventoryItem(const int index){
    if (Inventory[index] != nullptr) {
        return true;
    }
    else{
        return false;
    }
}

int Character::addInventoryItem(Item *item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if (Inventory[i] == nullptr) {
            this->Inventory[i] = item;
            cout << "Der Gegenstand \"" << this->Inventory[i]->getItemName() << "\" wurde dem Inventar von " << this->getName() << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item *Character::removeInventoryItem(int slot){
    if(slot >= 0 && slot <=INVENTORY_SIZE-1){
        if(this->Inventory[slot] != nullptr){
            cout << "Der Gegenstand \"" << this->Inventory[slot]->getItemName() << "\" wurde aus dem Inventar von " << this->getName() << " entfernt." << endl;
            this->Inventory[slot] = nullptr;
            return Inventory[slot];
        }
    }
    return nullptr;
}

int Character::addEquipmentItem(Item *item){
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if (Inventory[i] == nullptr) {
            this->Inventory[i] = item;
            cout << "Der Gegenstand \"" << this->Inventory[i]->getItemName() << "\" wurde dem Equipment von " << this->getName() << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item *Character::removeEquipmentItem(int slot){
    if(slot >= 0 && slot <=INVENTORY_SIZE-1) {
        if (this->Inventory[slot] != nullptr && this->Inventory[slot]->getEquipmentItem()) {
            cout << "Der Gegenstand \"" << this->Inventory[slot]->getItemName() << "\" wurde aus dem Equipment von " << this->getName() << " entfernt." << endl;
            this->Inventory[slot] = nullptr;
            return Inventory[slot];
        }
    }
    return nullptr;
}