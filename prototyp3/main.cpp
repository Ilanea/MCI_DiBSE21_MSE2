#include <iostream>
#include <ctime>
#include "character.h"
#include "hero.h"

using namespace std;


int main() {

    srand(time(nullptr));



    Hero annina("Annina", 300, 90, 50, 50);
    Item zauberstab((Item &) annina, "Zauberstab", 1000);
    annina.addEquipmentItem(zauberstab);

    Fighter enemy_matthias("Matthias", 50, 71, 10, 5, 50);
    Item buch((Item &) enemy_matthias, "C++ Buch", 1000);
    enemy_matthias.addInventoryItem(buch);
    Item compiler((Item &) enemy_matthias, "Magischer Compiler", 1001);
    enemy_matthias.addInventoryItem(compiler);

    Sorcerer enemy_pascal("Pascal", 100, 27, 15, 5, 50);
    Item trank((Item &) enemy_pascal, "Mathe Wissenstrank", 10000);
    enemy_pascal.addInventoryItem(trank);
    Item taschenrechner((Item &) enemy_pascal, "Taschenrechner", 5);
    enemy_pascal.addInventoryItem(taschenrechner);

    Fighter enemy_peter("Peter", 100, 100, 5, 5, 50);
    Item flasche((Item &) enemy_peter, "Sekt Flasche", 5000);
    enemy_peter.addInventoryItem(flasche);

    if(annina.fight(annina, enemy_matthias)){
        cout << enemy_matthias.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealthPoints() << " Lebenspunkte uebrig!" << endl;
        //annina.retrieveAllLoot(annina, enemy_matthias);
        annina.retrieveRandomLoot(annina, enemy_matthias);
    }
    else{
        cout << annina.getName() << " fiel in Ohnmacht!" << endl;
        return 0;
    }


    if(annina.fight(annina, enemy_pascal)){
        cout << enemy_pascal.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealthPoints() << " Lebenspunkte uebrig!" << endl;
        //annina.retrieveAllLoot(annina, enemy_pascal);
        annina.retrieveRandomLoot(annina, enemy_pascal);
    }
    else{
        cout << annina.getName() << " fiel in Ohnmacht!" << endl;
        return 0;
    }

    if(annina.fight(annina, enemy_peter)){
        cout << enemy_peter.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealthPoints() << " Lebenspunkte uebrig!" << endl;
        //annina.retrieveAllLoot(annina, enemy_pascal);
        annina.retrieveRandomLoot(annina, enemy_peter);
    }
    else{
        cout << annina.getName() << " fiel in Ohnmacht!" << endl;
        return 0;
    }

    for( int i = 0; i < INVENTORY_SIZE; i++ ){
        annina.sellLootItems(annina, i);
    }

    return 0;
}
