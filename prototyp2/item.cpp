//
// Created by msyu on 24.02.2022.
//

#include <iostream>
#include "item.h"

using namespace std;

void Item::initItem(Item &item, const string &name, const int gold){
    setItemName(name);
    setItemGold(gold);
    setItemValidity(true);
}

void Item::initItem(Item &item){
    setItemValidity(false);
}
