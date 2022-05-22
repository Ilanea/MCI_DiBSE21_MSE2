//
// Created by msyu on 5/21/22.
//

#ifndef FACTORY_MACHINE_H
#define FACTORY_MACHINE_H

#include <iostream>
#include "factory.h"

class Factory;

class Machine {
protected:
    Factory *factory;

public:
    bool disabled = false;
    bool exploded = false;

    Machine(){}

    virtual ~Machine(){
        std::cout << "Machine Destructor!" << std::endl;
    }

    virtual void tick() = 0;
    void setFactory(Factory* f);

    bool getDisabled(){
        return disabled;
    }

    void setDisabled(bool disabled){
        this->disabled = disabled;
    }

    bool getExploded(){
        return exploded;
    }

    void setExploded(bool exploded){
        this->exploded = exploded;
    }

};

class MachineA : public Machine {
public:
    void tick() override;
};

class MachineB : public Machine {
public:
    void tick() override;
};

#endif //FACTORY_MACHINE_H
