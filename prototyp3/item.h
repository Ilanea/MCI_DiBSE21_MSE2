//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_ITEM_H
#define PROTOTYP3_ITEM_H


#include <cstring>

using namespace std;

class Item
{

private:
    string ItemName;
    int ItemGold;
    bool isEquipment=false;
    bool isValid=false;
    bool wonItem=false;

public:

    //Konstruktor
    Item(){};

    Item(Item &item, const string &name, const int gold) : ItemName(name), ItemGold(gold), isValid(true) {
        cout << "Calling Item::Constructor" << std::endl;
    }

    //Destruktor
    ~Item(){

    }

    //void initItem(Item &item, const string &name, int gold);
    //void initItem(Item &item);

    const string getItemName(){
        return this->ItemName;
    }

    void setItemName(const string newItemName){
        ItemName = newItemName;
    }

    const int getItemGold(){
        return this->ItemGold;
    }

    void setItemGold(const int newItemGold){
        ItemGold = newItemGold;
    }

    const bool getItemValidity(){
        return this->isValid;
    }

    void setItemValidity(bool validity){
        isValid = validity;
    }

    const bool getItemWon(){
        return this->wonItem;
    }

    void setItemWon(bool won){
        wonItem = won;
    }

    const bool getEquipmentItem(){
        return this->isEquipment;
    }

    void setEquipmentItem(bool equipment){
        isEquipment = equipment;
    }

};

#endif //PROTOTYP3_ITEM_H
