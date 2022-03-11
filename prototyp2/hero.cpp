//
// Created by msyu on 24.02.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"

using namespace std;

void Hero::initHero(const string name, const int hp, const int gold){
    setHeroName(name);
    setHealthPoints(hp);
    setGold(gold);
}

void Hero::attack(Hero &hero, Character &enemy){
    if(enemy.getHealthPoints(enemy) > 0){
        int damage = 15 + rand() % 11;
        cout << hero.getHeroName(hero) << " trifft " << enemy.getCharacterName(enemy) << " fuer " << damage << " Lebenspunkte!" << endl;
        enemy.takeDamage(enemy, damage);
    }
}

void Hero::takeDamage(Hero &hero, const int damage){
    int new_hp = this->getHealthPoints(hero) - damage;
    this->setHealthPoints(new_hp);
}

bool Hero::fight(Hero &hero, Character &enemy){
    while(hero.getHealthPoints(hero) > 0 && enemy.getHealthPoints(enemy) > 0){
        hero.attack(hero, enemy);
        if (enemy.getHealthPoints(enemy) > 0) {
            enemy.attack(enemy, hero);
        }
    }

    return hero.getHealthPoints(hero);
}

int Hero::addEquipmentItem(Item &item){
    for(int i = 0; i < 10; i++) {
        if (!HeroInventory[i].getItemValidity()) {
            this->HeroInventory[i].setItemName(item.getItemName());
            this->HeroInventory[i].setItemGold(item.getItemGold());
            this->HeroInventory[i].setItemValidity(true);
            this->HeroInventory[i].setEquipmentItem(true);
            cout << "Der Gegenstand \"" << this->HeroInventory[i].getItemName() << "\" wurde dem Equipment von " << this->HeroName << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item Hero::removeEquipmentItem(int slot){
    if(slot >= 0 && slot <=9) {
        if (this->HeroInventory[slot].getItemValidity() && this->HeroInventory[slot].getEquipmentItem()) {
            this->HeroInventory[slot].setItemValidity(false);
            cout << "Der Gegenstand \"" << this->HeroInventory[slot].getItemName() << "\" wurde aus dem Equipment von "
                 << this->HeroName << " entfernt." << endl;
            return this->HeroInventory[slot];
        }
    }
}

int Hero::addInventoryItem(Item &item){
    for(int i = 0; i < 10; i++) {
        if (!HeroInventory[i].getItemValidity()) {
            this->HeroInventory[i].setItemName(item.getItemName());
            this->HeroInventory[i].setItemGold(item.getItemGold());
            this->HeroInventory[i].setItemValidity(true);
            cout << "Der Gegenstand \"" << this->HeroInventory[i].getItemName() << "\" wurde dem Inventar von " << this->HeroName << " hinzugefuegt." << endl;
            return i;
        }
    }
    return -1;
}

Item Hero::removeInventoryItem(int slot){
    if(slot >= 0 && slot <=9) {
        if (this->HeroInventory[slot].getItemValidity()) {
            this->HeroInventory[slot].setItemValidity(false);
            //cout << "Der Gegenstand \"" << this->HeroInventory[slot].getItemName() << "\" wurde aus dem Inventar von " << this->HeroName << " entfernt." << endl;
            return this->HeroInventory[slot];
        }
    }
}

void Hero::getAllItems(Hero &hero, Character &enemy){
    int new_gold = this->getGold(hero) + enemy.getGold(enemy);
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getCharacterName(enemy) << " " << enemy.getGold(enemy) << " Gold und besitzt nun " << this->getGold(hero) << " Gold." << endl;
    for(int i = 0; i < 10; i++){
        if(enemy.checkInventoryItem(i)){
            for(int j = 0; j < 10; j++){
                if(!this->HeroInventory[j].getItemValidity()){
                    this->addInventoryItem(*enemy.getInventoryItem(i));
                    this->HeroInventory[j].setItemWon(true);
                    enemy.removeInventoryItem(i);
                    //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
                    break;
                }
                if(this->HeroInventory[9].getItemValidity()){
                    cout << "Das Inventar der Heldin ist voll und es koennen keine weiteren Gegenstaende mehr aufgenommen werden." << endl;
                    cout << "Der Gegenstand \"" << enemy.getInventoryItem(i)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
                    break;
                }
            }
        }
    }
}

void Hero::getRandomItem(Hero &hero, Character &enemy){
    int new_gold = this->getGold(hero) + enemy.getGold(enemy);
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getCharacterName(enemy) << " " << enemy.getGold(enemy) << " Gold und besitzt nun " << this->getGold(hero) << " Gold." << endl;

    int enemyItemCount = 0;

    for(int i = 0; i < 10; i++){
        if(enemy.checkInventoryItem(i)){
            enemyItemCount++;
        }
    }

    int randomItem = rand()%enemyItemCount;

    for(int j = 0; j < 10; j++){
        if(!this->HeroInventory[j].getItemValidity()){
            this->addInventoryItem(*enemy.getInventoryItem(randomItem));
            this->HeroInventory[j].setItemWon(true);
            enemy.removeInventoryItem(randomItem);
            //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
            break;
        }
        if(this->HeroInventory[9].getItemValidity()){
            cout << "Kein Platz mehr vorhanden!" << endl;
            cout << "Der Gegenstand \"" << enemy.getInventoryItem(randomItem)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
            break;
        }
    }

}

void Hero::sellAllItems(Hero &hero, int index) {
    if(index >= 0 && index < 10){
        if(this->HeroInventory[index].getItemValidity()){
            int new_gold = this->getGold(hero) + this->HeroInventory[index].getItemGold();
            this->setGold(new_gold);
            this->removeInventoryItem(index);
            cout << "Gegenstand \"" << this->HeroInventory[index].getItemName() << "\" wurde verkauft." << endl;
            cout << this->getHeroName(hero) << " besitzt nun " << this->getGold(hero) << " Gold." << endl;
        }
    }
}

void Hero::sellWonItems(Hero &hero, int index) {
    if(index >= 0 && index < 10){
        if(this->HeroInventory[index].getItemValidity() && this->HeroInventory[index].getItemWon()){
            int new_gold = this->getGold(hero) + this->HeroInventory[index].getItemGold();
            this->setGold(new_gold);
            this->removeInventoryItem(index);
            cout << "Gegenstand \"" << this->HeroInventory[index].getItemName() << "\" wurde verkauft." << endl;
            cout << this->getHeroName(hero) << " besitzt nun " << this->getGold(hero) << " Gold." << endl;
        }
    }
}