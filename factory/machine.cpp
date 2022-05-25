//
// Created by msyu on 5/21/22.
//

#include "machine.h"
#include <algorithm>
#include "exception.h"

void Machine::setFactory(Factory* f){
    this->factory = f;
}

void MachineA::tick() {

    int randomnumber = rand() % 100 + 1;

    if(randomnumber <= 2){
        throw MachineExplosionException("MachineA::tick(): MachineExplosionException");
    }else if(randomnumber >= 3 && randomnumber <= 18){
        throw MachineFailureException("MachineA::tick(): MachineFailureException");
    }
    else{
        for (int i = 0; i < 2; ++i) {
            ProductA *product = new ProductA();
            this->factory->addProduct(product);
        }
    }
}

void MachineB::tick() {

    int randomnumber = rand() % 100 + 1;

    if(randomnumber <= 20){
        throw MachineExplosionException("MachineA::tick(): MachineExplosionException");
    }else if(randomnumber >= 21 && randomnumber <= 25){
        throw MachineFailureException("MachineA::tick(): MachineFailureException");
    }
    else{
        for (int i = 0; i < 3; ++i) {
            ProductB * product = new ProductB();
            this->factory->addProduct(product);
        }
    }
}