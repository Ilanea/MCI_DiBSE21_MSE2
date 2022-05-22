
#include <ctime>
#include <iostream>
#include "factory.h"
#include "machine.h"

int main() {

    srand(time(nullptr));

    try{

        Factory factory;

        Machine* machineA = new(MachineA);
        Machine* machineB = new(MachineB);
        factory.addMachine(machineA);
        factory.addMachine(machineB);
        machineA->setFactory(&factory);
        machineB->setFactory(&factory);

        factory.run(10);

        std::cout << "Wir haben " << factory.getProductACount() << " Stueck von Produkt A." << std::endl;
        std::cout << "Wir haben " << factory.getProductBCount() << " Stueck von Produkt B." << std::endl;



    }  catch (std::exception &error){
        std::cerr << "Exception in Main: " << error.what() << std::endl;
    }

    return 0;
}
