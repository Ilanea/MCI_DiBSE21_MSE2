//
// Created by msyu on 5/21/22.
//

#include <unistd.h>
#include <list>
#include "factory.h"
#include "exception.h"

// Wir fuegen eine Maschine hinzu mit einer eindeutigen ID
unsigned Factory::addMachine(Machine *m) {
    int id = nextId++;
    Machines.insert({id,m});
    return nextId;
}

// Wir suchen eine Maschine mit einer ID, sollte diese existieren geben wir den Pointer darauf zurück, wenn nicht werfen wir eine Exception
Machine *Factory::getMachine(unsigned int id) {
    if (Machines.find(id) != Machines.end()) {
        return Machines[id];
    }
    else{
        throw MachineFailureException("Factory::getMachine(): Machine does not exist!");
    }
}

// Wir checken ob es eine Machine mit dieser ID gibt, wenn ja loeschen wir diese, wenn nein dann geben wir eine Exception aus
void Factory::deleteMachine(unsigned int id) {
    if(Machines.find(id) != Machines.end()){
        delete getMachine(id);
        Machines.erase(id);
        std::cout << "Machine #" << id << " deleted!" << std::endl;
    }
    else{
        throw MachineFailureException("Factory::deleteMachine(): Machine does not exist!");
    }
}

// Wir fuegen ein Produkt unseren Vektoren A oder B zu je nachdem welchen getType diese zurückgeben.
void Factory::addProduct(Product *p) {
    if(p->getType() == 1){
        ProductsA.push_back(p);
    } else if(p->getType() == 2) {
        ProductsB.push_back(p);
    };
}

// Wir geben die size vom Vector ProductsA zurück welche die Anzahl enthält
unsigned Factory::getProductACount() {
    return ProductsA.size();
}

// Wir geben die size vom Vector ProductsB zurück welche die Anzahl enthält
unsigned Factory::getProductBCount() {
    return ProductsB.size();
}

void Factory::run(unsigned int iterations) {

    int TickCount = 0;
    std::list<unsigned > deletedList;

    // Wir gehen jede Iteration alle Maschinen durch und führen einen Tick aus, wenn die Machine eine MachineFailureException bringt
    // sollte diese Maschine auf den Status "Disabled = true" gesetzt werden und 3 Iterationen aussetzen.
    // Wenn eine Machine explodiert wird diese den Status "Exploded = true" bekommen.
    // Es sollen nur Maschinen einen tick ausführen welche keinen Status (Exploded oder Disabled) true haben.
    // Der Status Exploded wird sich wenn einmal gesetzt nichtmehr entfernen, der Status Disabled setzt sich nach 3 Ticks zurück.
    while(iterations >= 0){

        for (auto &Machine: Machines) {
            try {
                if(!Machine.second->getDisabled() && !Machine.second->getExploded()){
                    Machine.second->tick();
                    std::cout << "Maschine #" << Machine.first  << " hat Produkte erzeugt!" << std::endl;
                }
            }
            catch (MachineFailureException &e) {
                std::cout << "Maschine #" << Machine.first  << " hat einen Fehler produziert und muss fuer 3 Ticks aussetzen" << std::endl;
                if(TickCount == 0){
                    TickCount = 3;
                    Machine.second->setDisabled(true);
                }
            }
            catch (MachineExplosionException &e) {
                std::cout << "Maschine #" << Machine.first  << " ist explodiert und muss entfernt werden!" << std::endl;
                Machine.second->setExploded(true);
                deletedList.push_front(Machine.first);
            }

        }

        if(TickCount != 0){
            std::cout << "Maschine setzt noch aus!" << std::endl;
            TickCount--;
        }

        if(TickCount == 0){
            for (auto &Machine: Machines){
                if(Machine.second->getDisabled()){
                    Machine.second->setDisabled(false);
                }
            }
        }


        if (iterations > 0) {
            iterations--;
            if (iterations <= 0) {
                break;
            }
        }

        if(getMachineCount() == 0){
            std::cout << "Wir haben keine Maschinen mehr, beende die Produktion." << std::endl;
            break;
        }

        for (unsigned id: deletedList) {
            this->deleteMachine(id);
        }
        deletedList.clear();


        sleep(1);

    }
}
