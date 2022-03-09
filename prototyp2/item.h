//
// Created by msyu on 24.02.2022.
//

#ifndef PROTOTYP_ITEM_H
#define PROTOTYP_ITEM_H

#include <string.h>

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

    void initItem(Item &item, const string &name, int gold);
    void initItem(Item &item);

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



#endif //PROTOTYP_ITEM_H
