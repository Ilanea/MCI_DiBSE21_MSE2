//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"


using namespace std;

void Character::attack(Hero &hero, Character &enemy){
    if(hero.getHealthPoints(hero) > 0 && enemy.getHealthPoints(enemy)){
        int damage = 15 + rand() % 25 - getArmor(enemy);
        if(damage >= 0){
            enemy.takeDamage(enemy, damage);
            cout << hero.getName(hero) << " trifft " << enemy.getName(enemy) << " fuer " << damage << " Lebenspunkte!" << endl;
        }
        else{
            cout << hero.getName(hero) << " verfehlt " << enemy.getName(enemy) << " !" << endl;
        }
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
    for(int i = 0; i < INVENTORY_SIZE; i++) {
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
    if(slot >= 0 && slot <=INVENTORY_SIZE-1){
        if(this->Inventory[slot].getItemValidity()){
            this->Inventory[slot].setItemValidity(false);
            cout << "Der Gegenstand \"" << this->Inventory[slot].getItemName() << "\" wurde aus dem Inventar von " << this->Name << " entfernt." << endl;
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
            cout << "Der Gegenstand \"" << this->Inventory[i].getItemName() << "\" wurde dem Equipment von " << this->Name << " hinzugefuegt." << endl;
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
                 << this->Name << " entfernt." << endl;
            return this->Inventory[slot];
        }
    }
    return Item();
}