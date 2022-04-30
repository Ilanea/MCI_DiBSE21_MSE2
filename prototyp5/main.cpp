#include <iostream>
#include <ctime>
#include "character.h"
#include "hero.h"
#include <memory>

using namespace std;


int main() {

    srand(time(nullptr));


    try{
        Hero annina("Annina", 300, 90, 50, 50);
        annina.addEquipmentItem(std::shared_ptr<Item>(new Item((Item &) annina, "Zauberstab", 1000)));

        Fighter enemy_matthias("Matthias", 50, 71, 10, 5, 50);
        enemy_matthias.addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_matthias, "C++ Buch", 1000)));
        enemy_matthias.addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_matthias, "Magischer Compiler", 1001)));

        Sorcerer enemy_pascal("Pascal", 100, 27, 15, 5, 50);
        enemy_pascal.addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_pascal, "Mathe Trank", 10000)));
        enemy_pascal.addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_pascal, "Taschenrechner", 5)));

        cout << "---------------------------------- Fight 1 ----------------------------------" << endl;

        if(annina.fight(annina, enemy_matthias)){
            cout << enemy_matthias.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealthPoints() << " Lebenspunkte uebrig!" << endl;
            annina.retrieveRandomLoot(annina, enemy_matthias);
        }
        else{
            cout << annina.getName() << " fiel in Ohnmacht!" << endl;
            return 0;
        }

        cout << "---------------------------------- Fight 2 ----------------------------------" << endl;

        if(annina.fight(annina, enemy_pascal)){
            cout << enemy_pascal.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealthPoints() << " Lebenspunkte uebrig!" << endl;
            annina.retrieveRandomLoot(annina, enemy_pascal);
        }
        else{
            cout << annina.getName() << " fiel in Ohnmacht!" << endl;
            return 0;
        }

        cout << "---------------------------------- Verkaufen ----------------------------------" << endl;

        annina.sellLootItems(annina);

    }  catch (std::exception &error){
        std::cerr << "Exception in Main: " << error.what() << std::endl;
    }


    return 0;
}
