//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"

using namespace std;

bool Hero::fight(Hero &hero, Character &enemy){
    do{
        this->attack(hero, static_cast<Hero &>(enemy));
        if (enemy.getHealthPoints(enemy) > 0) {
            this->attack(static_cast<Hero &>(enemy), hero);
        }
        else{
            return true;
        }
    }while(hero.getHealthPoints(hero) > 0 && enemy.getHealthPoints(enemy) > 0);

    return false;
}


void Hero::retrieveAllLoot(Hero &hero, Character &enemy){
    int new_gold = this->getGold(hero) + enemy.getGold(enemy);
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getName(enemy) << " " << enemy.getGold(enemy) << " Gold und besitzt nun " << this->getGold(hero) << " Gold." << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(enemy.checkInventoryItem(i)){
            for(int j = 0; j < INVENTORY_SIZE; j++){
                if(!this->Inventory[j].getItemValidity()){
                    this->addInventoryItem(*enemy.getInventoryItem(i));
                    this->Inventory[j].setItemWon(true);
                    enemy.removeInventoryItem(i);
                    //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
                    break;
                }
                if(this->Inventory[INVENTORY_SIZE-1].getItemValidity()){
                    cout << "Das Inventar der Heldin ist voll und es koennen keine weiteren Gegenstaende mehr aufgenommen werden." << endl;
                    cout << "Der Gegenstand \"" << enemy.getInventoryItem(i)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
                    break;
                }
            }
        }
    }
}

void Hero::retrieveRandomLoot(Hero &hero, Character &enemy){
    int new_gold = this->getGold(hero) + enemy.getGold(enemy);
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getName(enemy) << " " << enemy.getGold(enemy) << " Gold und besitzt nun " << this->getGold(hero) << " Gold." << endl;

    int enemyItemCount = 0;

    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(enemy.checkInventoryItem(i)){
            enemyItemCount++;
        }
    }

    int randomItem = rand()%enemyItemCount;

    for(int j = 0; j < INVENTORY_SIZE; j++){
        if(!this->Inventory[j].getItemValidity()){
            this->addInventoryItem(*enemy.getInventoryItem(randomItem));
            this->Inventory[j].setItemWon(true);
            enemy.removeInventoryItem(randomItem);
            //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
            break;
        }
        if(this->Inventory[INVENTORY_SIZE-1].getItemValidity()){
            cout << "Kein Platz mehr vorhanden!" << endl;
            cout << "Der Gegenstand \"" << enemy.getInventoryItem(randomItem)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
            break;
        }
    }

}

void Hero::sellAllItems(Hero &hero, int index) {
    if(index >= 0 && index < INVENTORY_SIZE){
        if(this->Inventory[index].getItemValidity()){
            int new_gold = this->getGold(hero) + this->Inventory[index].getItemGold();
            this->setGold(new_gold);
            this->removeInventoryItem(index);
            cout << "Gegenstand \"" << this->Inventory[index].getItemName() << "\" wurde verkauft." << endl;
            cout << this->getName(hero) << " besitzt nun " << this->getGold(hero) << " Gold." << endl;
        }
    }
}

void Hero::sellLootItems(Hero &hero, int index) {
    if(index >= 0 && index < INVENTORY_SIZE){
        if(this->Inventory[index].getItemValidity() && this->Inventory[index].getItemWon()){
            int new_gold = this->getGold(hero) + this->Inventory[index].getItemGold();
            this->setGold(new_gold);
            this->removeInventoryItem(index);
            cout << "Gegenstand \"" << this->Inventory[index].getItemName() << "\" wurde verkauft." << endl;
            cout << this->getName(hero) << " besitzt nun " << this->getGold(hero) << " Gold." << endl;
        }
    }
}