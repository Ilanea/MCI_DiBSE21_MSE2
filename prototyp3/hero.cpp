//
// Created by msyu on 21.03.2022.
//

#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"

using namespace std;

void Hero::attack(Hero &hero, Character &enemy){
    if(enemy.getHealthPoints(enemy) > 0){
        int damage = 15 + rand() % 11;
        cout << hero.getName(hero) << " trifft " << enemy.getName(enemy) << " fuer " << damage << " Lebenspunkte!" << endl;
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


void Hero::getAllItems(Hero &hero, Character &enemy){
    int new_gold = this->getGold(hero) + enemy.getGold(enemy);
    hero.setGold(new_gold);
    cout << "Annina stiehlt " << enemy.getName(enemy) << " " << enemy.getGold(enemy) << " Gold und besitzt nun " << this->getGold(hero) << " Gold." << endl;
    for(int i = 0; i < 10; i++){
        if(enemy.checkInventoryItem(i)){
            for(int j = 0; j < 10; j++){
                if(!this->Inventory[j].getItemValidity()){
                    this->addInventoryItem(*enemy.getInventoryItem(i));
                    this->Inventory[j].setItemWon(true);
                    enemy.removeInventoryItem(i);
                    //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
                    break;
                }
                if(this->Inventory[9].getItemValidity()){
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
    cout << "Annina stiehlt " << enemy.getName(enemy) << " " << enemy.getGold(enemy) << " Gold und besitzt nun " << this->getGold(hero) << " Gold." << endl;

    int enemyItemCount = 0;

    for(int i = 0; i < 10; i++){
        if(enemy.checkInventoryItem(i)){
            enemyItemCount++;
        }
    }

    int randomItem = rand()%enemyItemCount;

    for(int j = 0; j < 10; j++){
        if(!this->Inventory[j].getItemValidity()){
            this->addInventoryItem(*enemy.getInventoryItem(randomItem));
            this->Inventory[j].setItemWon(true);
            enemy.removeInventoryItem(randomItem);
            //cout << "Gegenstand \"" << enemy.CharacterInventory[i].getItemName() << "\" wurde zum Inventar der Heldin hinzugefuegt." << endl;
            break;
        }
        if(this->Inventory[9].getItemValidity()){
            cout << "Kein Platz mehr vorhanden!" << endl;
            cout << "Der Gegenstand \"" << enemy.getInventoryItem(randomItem)->getItemName() << "\" bleibt leider am Boden liegen." << endl;
            break;
        }
    }

}

void Hero::sellAllItems(Hero &hero, int index) {
    if(index >= 0 && index < 10){
        if(this->Inventory[index].getItemValidity()){
            int new_gold = this->getGold(hero) + this->Inventory[index].getItemGold();
            this->setGold(new_gold);
            this->removeInventoryItem(index);
            cout << "Gegenstand \"" << this->Inventory[index].getItemName() << "\" wurde verkauft." << endl;
            cout << this->getName(hero) << " besitzt nun " << this->getGold(hero) << " Gold." << endl;
        }
    }
}

void Hero::sellWonItems(Hero &hero, int index) {
    if(index >= 0 && index < 10){
        if(this->Inventory[index].getItemValidity() && this->Inventory[index].getItemWon()){
            int new_gold = this->getGold(hero) + this->Inventory[index].getItemGold();
            this->setGold(new_gold);
            this->removeInventoryItem(index);
            cout << "Gegenstand \"" << this->Inventory[index].getItemName() << "\" wurde verkauft." << endl;
            cout << this->getName(hero) << " besitzt nun " << this->getGold(hero) << " Gold." << endl;
        }
    }
}