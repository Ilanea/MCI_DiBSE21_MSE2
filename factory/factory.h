//
// Created by msyu on 5/21/22.
//

#ifndef FACTORY_FACTORY_H
#define FACTORY_FACTORY_H

#include <map>
#include <memory>
#include <vector>
#include "product.h"
#include "machine.h"

class Machine;

class Product;

class Factory {
protected:
    std::map<unsigned const int, Machine*> Machines;
    std::vector<Product*> ProductsA;
    std::vector<Product*> ProductsB;
    int nextId = 0;

public:
    ~Factory(){
        std::cout << "Factory Destructor!" << std::endl;
        for(int i=0; i <= this->getMachineCount(); i++){
            if(this->getMachine(i) != nullptr){
                this->deleteMachine(i);
            }
        }
        Machines.clear();
        for(int j=0; j < getProductACount(); j++){
            delete ProductsA.at(j);
        }
        ProductsA.clear();
        for(int k=0; k < getProductBCount(); k++){
            delete ProductsB.at(k);
        }
        ProductsB.clear();
    }
    unsigned addMachine(Machine* m);
    Machine* getMachine(unsigned id);
    void deleteMachine(unsigned id);
    void addProduct(Product* p);
    unsigned getProductACount();
    unsigned getProductBCount();
    void run(unsigned iterations);

    const int getMachineCount(){
        return Machines.size();
    }

};


#endif //FACTORY_FACTORY_H
