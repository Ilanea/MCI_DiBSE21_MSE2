//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "game.h"

std::ostream& operator<<(std::ostream& out, Item item) {
    out << item.getItemName() << " (Gold: " << item.getItemGold() <<  ")";
    return out;
}

void Hero::attack(Hero &hero, Character &enemy){
    if(hero.getHealthPoints() > 0 && enemy.getHealthPoints()){
        int damage = rand() % ((25 - 15) + 1) + 15 - enemy.getArmor();
        //std::cout << "-------------------------------------------------------------------------" << std::endl;
        //std::cout << "Armor: " << enemy.getArmor(enemy) << endl;
        //std::cout << "Damage: " << damage << endl;
        int newHP = enemy.getHealthPoints() - damage;
        if(damage >= 0){
            enemy.setHealthPoints(newHP);
            std::cout << hero.getName() << " trifft " << enemy.getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
        }
        else{
            std::cout << hero.getName() << " verfehlt " << enemy.getName() << " !" << std::endl;
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
    std::cout << "Annina stiehlt " << enemy.getName() << " " << enemy.getGold() << " Gold und besitzt nun " << this->getGold() << " Gold." << std::endl;

    if(enemy.InventoryCount != 0){
        for(int index = enemy.InventoryCount-1; index >= 0; index--){
            this->addInventoryItem(*enemy.getInventoryItem(index));
            this->Inventory.back()->setEquipmentItem(false);
            enemy.removeInventoryItem(index);
            //std::cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
        }
    }
    else{
        throw InventoryOutOfRange("Hero::retrieveAllLoot(): Enemy Inventory Empty");
    }

}

std::shared_ptr<Item> Hero::retrieveRandomLoot(Hero &hero, Character &enemy){
    int new_gold = this->getGold() + enemy.getGold();
    hero.setGold(new_gold);
    std::cout << "Annina stiehlt " << enemy.getName() << " " << enemy.getGold() << " Gold und besitzt nun " << this->getGold() << " Gold." << std::endl;

    if(enemy.InventoryCount != 0){
        int randomItem = rand()%enemy.InventoryCount;

        std::shared_ptr<Item> *lootItem = enemy.getInventoryItem(randomItem);

        this->addInventoryItem(*lootItem);
        this->Inventory.back()->setEquipmentItem(false);
        enemy.removeInventoryItem(randomItem);
        //std::cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << std::endl;

        return *lootItem;
    }
    else{
        throw InventoryOutOfRange("Hero::retrieveAllLoot(): Enemy Inventory Empty");
    }


}

void Hero::sellLootItems(Hero &hero) {
    for(int index = hero.Inventory.size()-1; index >= 0; index--){
        if(!this->Inventory[index]->getEquipmentItem()){
            int new_gold = this->getGold() + this->Inventory[index]->getItemGold();
            this->setGold(new_gold);
            std::cout << "Gegenstand \"" << this->Inventory[index]->getItemName() << "\" wurde verkauft." << std::endl;
            this->removeInventoryItem(index);
            //Inventory.erase(Inventory.begin()+index);
            std::cout << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        }
    }
}

void Hero::sellAllItems(Hero &hero) {
    for(int index = hero.Inventory.size()-1; index >= 0; index--){
        int new_gold = this->getGold() + this->Inventory[index]->getItemGold();
        this->setGold(new_gold);
        std::cout << "Gegenstand \"" << this->Inventory[index]->getItemName() << "\" wurde verkauft." << std::endl;
        this->removeInventoryItem(index);
        std::cout << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
    }
}