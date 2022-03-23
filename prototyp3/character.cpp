//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

using namespace std;

void Character::attack(Character &character, Hero &hero){
    if(hero.getHealthPoints(hero) > 0) {
        int damage = 5 + rand() % 11;
        cout << character.getName(character) << " trifft " << hero.getName(hero) << " fuer " << damage << " Lebenspunkte!" << endl;
        hero.takeDamage(hero, damage);
    }
}

void Character::takeDamage(Character &character, const int damage){
    int new_hp = this->getHealthPoints(character) - damage;
    this->setHealthPoints(new_hp);
}

bool Character::checkInventoryItem(const int index){
    if (Inventory[index].getItemValidity()) {
        return true;
    }
    else{
        return false;
    }
}

int Character::addInventoryItem(Item &item){
    for(int i = 0; i < 10; i++) {
        if (!Inventory[i].getItemValidity()) {
            this->Inventory[i].setItemName(item.getItemName());
            this->Inventory[i].setItemGold(item.getItemGold());
            this->Inventory[i].setItemValidity(true);
            cout << "Der Gegenstand \"" << this->Inventory[i].getItemName() << "\" wurde dem Inventar von " << this->Name << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item Character::removeInventoryItem(int slot){
    if(slot >= 0 && slot <=9){
        if(this->Inventory[slot].getItemValidity()){
            this->Inventory[slot].setItemValidity(false);
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Inventar von " << this->Name << " entfernt." << endl;
            return this->Inventory[slot];
        }
    }
    return Item();
}

int Character::addEquipmentItem(Item &item){
    for(int i = 0; i < 10; i++) {
        if (!Inventory[i].getItemValidity()) {
            this->Inventory[i].setItemName(item.getItemName());
            this->Inventory[i].setItemGold(item.getItemGold());
            this->Inventory[i].setItemValidity(true);
            this->Inventory[i].setEquipmentItem(true);
            cout << "Der Gegenstand \"" << this->Inventory[i].getItemName() << "\" wurde dem Equipment von " << this->Name << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item Character::removeEquipmentItem(int slot){
    if(slot >= 0 && slot <=9) {
        if (this->Inventory[slot].getItemValidity() && this->Inventory[slot].getEquipmentItem()) {
            this->Inventory[slot].setItemValidity(false);
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Equipment von "
                 << this->Name << " entfernt." << endl;
            return this->Inventory[slot];
        }
    }
    return Item();
}