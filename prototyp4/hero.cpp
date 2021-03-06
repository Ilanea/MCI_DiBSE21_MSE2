//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "exception.h"

using namespace std;

std::ostream& operator<<(std::ostream& out, Item item) {
    out << item.getItemName() << " (Gold: " << item.getItemGold() <<  ")";
    return out;
}

void Hero::attack(Hero &hero, Character &enemy){
    if(hero.getHealthPoints() > 0 && enemy.getHealthPoints()){
        int damage = rand() % ((25 - 15) + 1) + 15 - enemy.getArmor();
        //cout << "-------------------------------------------------------------------------" << endl;
        //cout << "Armor: " << enemy.getArmor(enemy) << endl;
        //cout << "Damage: " << damage << endl;
        int newHP = enemy.getHealthPoints() - damage;
        if(damage >= 0){
            enemy.setHealthPoints(newHP);
            cout << hero.getName() << " trifft " << enemy.getName() << " fuer " << damage << " Lebenspunkte!" << endl;
        }
        else{
            cout << hero.getName() << " verfehlt " << enemy.getName() << " !" << endl;
        }
        //cout << "-------------------------------------------------------------------------" << endl;
    }
}

bool Hero::fight(Hero &hero, Character &enemy){
    do{
        this->attack(hero, enemy);
        if (enemy.getHealthPoints() > 0) {
            enemy.attack(hero, enemy);
        }
        else{
            return true;
        }
    }while(hero.getHealthPoints() > 0 && enemy.getHealthPoints() > 0);

    return false;
}


void Hero::retrieveAllLoot(Hero &hero, Character &enemy){
    int new_gold = this->getGold() + enemy.getGold();
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getName() << " " << enemy.getGold() << " Gold und besitzt nun " << this->getGold() << " Gold." << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(enemy.checkInventoryItem(i)){
            for(int j = 0; j < INVENTORY_SIZE; j++){
                if(this->Inventory[j] == nullptr){
                    this->addInventoryItem(enemy.getInventoryItem(i));
                    this->Inventory[j]->setEquipmentItem(false);
                    enemy.removeInventoryItem(i);
                    //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
                    break;
                }
                if(this->Inventory[INVENTORY_SIZE-1] != nullptr){
                    cout << "Das Inventar der Heldin ist voll und es koennen keine weiteren Gegenstaende mehr aufgenommen werden." << endl;
                    cout << "Der Gegenstand \"" << enemy.getInventoryItem(i)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
                    throw InventoryFull("Hero::retrieveRandomLoot: No more Space in Inventory.");
                }
            }
        }
    }
}

Item Hero::retrieveRandomLoot(Hero &hero, Character &enemy){
    int new_gold = this->getGold() + enemy.getGold();
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getName() << " " << enemy.getGold() << " Gold und besitzt nun " << this->getGold() << " Gold." << endl;

    int enemyItemCount = 0;

    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(enemy.checkInventoryItem(i)){
            enemyItemCount++;
        }
    }

    int randomItem = rand()%enemyItemCount;

    Item *lootItem = enemy.getInventoryItem(randomItem);

    for(int j = 0; j < INVENTORY_SIZE; j++){
        if(this->Inventory[j] == nullptr){
            this->addInventoryItem(lootItem);
            this->Inventory[j]->setEquipmentItem(false);
            enemy.removeInventoryItem(randomItem);
            //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
            break;
        }
        if(this->Inventory[INVENTORY_SIZE-1] != nullptr){
            cout << "Kein Platz mehr vorhanden!" << endl;
            cout << "Der Gegenstand \"" << enemy.getInventoryItem(randomItem)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
            throw InventoryFull("Hero::retrieveRandomLoot: No more Space in Inventory.");
        }
    }

    return *lootItem;

}

void Hero::sellAllItems(Hero &hero, int index) {
    if(index >= 0 && index < INVENTORY_SIZE){
        if(this->Inventory[index] != nullptr){
            int new_gold = this->getGold() + this->Inventory[index]->getItemGold();
            this->setGold(new_gold);
            cout << "Gegenstand \"" << this->Inventory[index]->getItemName() << "\" wurde verkauft." << endl;
            //this->removeInventoryItem(index);
            delete Inventory[index];
            Inventory[index] = nullptr;
            cout << this->getName() << " besitzt nun " << this->getGold() << " Gold." << endl;
        }
    }
    else{
        throw InventoryOutOfRange("Hero::sellAllItems: Inventory Check out of Range of Inventory Size.");
    }
}

void Hero::sellLootItems(Hero &hero, int index) {
    if(index >= 0 && index < INVENTORY_SIZE){
        if(this->Inventory[index] != nullptr && !this->Inventory[index]->getEquipmentItem()){
            int new_gold = this->getGold() + this->Inventory[index]->getItemGold();
            this->setGold(new_gold);
            cout << "Gegenstand \"" << this->Inventory[index]->getItemName() << "\" wurde verkauft." << endl;
            //this->removeInventoryItem(index);
            delete Inventory[index];
            Inventory[index] = nullptr;
            cout << this->getName() << " besitzt nun " << this->getGold() << " Gold." << endl;
        }
    }
    else{
        throw InventoryOutOfRange("Hero::sellLootItems: Inventory Check out of Range of Inventory Size.");
    }
}