//
// Created by msyu on 24.02.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"

using namespace std;


void Character::initCharacter(string name, const int hp, const int gold){
    setCharacterName(name);
    setHealthPoints(hp);
    setGold(gold);
}

void Character::attack(Character &character, Hero &hero){
    if(hero.getHealthPoints(hero) > 0) {
        int damage = 5 + rand() % 11;
        cout << character.getCharacterName(character) << " trifft " << hero.getHeroName(hero) << " fuer " << damage << " Lebenspunkte!" << endl;
        hero.takeDamage(hero, damage);
    }
}

void Character::takeDamage(Character &character, const int damage){
    int new_hp = this->getHealthPoints(character) - damage;
    this->setHealthPoints(new_hp);
}

bool Character::checkInventoryItem(const int index){
    if (CharacterInventory[index].getItemValidity()) {
        return true;
    }
    else{
        return false;
    }
}

int Character::addInventoryItem(Item &item){
    for(int i = 0; i < 10; i++) {
        if (!CharacterInventory[i].getItemValidity()) {
            this->CharacterInventory[i].setItemName(item.getItemName());
            this->CharacterInventory[i].setItemGold(item.getItemGold());
            this->CharacterInventory[i].setItemValidity(true);
            cout << "Der Gegenstand \"" << this->CharacterInventory[i].getItemName() << "\" wurde dem Inventar von " << this->CharacterName << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item *Character::removeInventoryItem(int slot){
    if(this->CharacterInventory[slot].getItemValidity()){
        this->CharacterInventory[slot].setItemValidity(false);
        cout << "Der Gegenstand \"" << this->CharacterInventory[slot].getItemName() << "\" wurde aus dem Inventar von " << this->CharacterName << " entfernt." << endl;
        return &this->CharacterInventory[slot];
    }
    return nullptr;
}