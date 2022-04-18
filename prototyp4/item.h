//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP3_ITEM_H
#define PROTOTYP3_ITEM_H


#include <cstring>
#include "exception.h"

using namespace std;

class Item
{

private:
    string ItemName;
    int ItemGold;
    bool isEquipment=true;

public:

    //Konstruktor
    Item(){};

    Item(Item &item, const string &name, const int gold) : ItemName(name), ItemGold(gold) {

        if(name.empty() || gold < 0){
            throw InvalidConstructorException("Item::Constructor: Name cannot be empty, Gold cannot have negative value.");
        }

        cout << "Calling Item::Constructor" << std::endl;
    }

    //Destruktor
    ~Item(){
        cout << "Calling Item::Destructor" << std::endl;
    }

    //void initItem(Item &item, const string &name, int gold);
    //void initItem(Item &item);

    const string getItemName(){
        return this->ItemName;
    }

    const int getItemGold(){
        return this->ItemGold;
    }

    void setItemGold(const int newItemGold){
        if(newItemGold < 0){
            throw InvalidGoldException("Item::setItemGold(): Gold cannot be a negative value.");
        }
        else{
            this->ItemGold = newItemGold;
        }
    }

    const bool getEquipmentItem(){
        return this->isEquipment;
    }

    void setEquipmentItem(bool equipment){
        isEquipment = equipment;
    }

};

#endif //PROTOTYP3_ITEM_H
