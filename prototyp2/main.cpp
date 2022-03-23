#include <iostream>
#include <ctime>
#include "character.h"

using namespace std;


int main() {

    srand(time(nullptr));

    Item item;

    Hero annina;
    annina.initHero("Annina", 30, 90);
    item.initItem((Item &) annina, "Zauberstab", 1000);
    annina.addEquipmentItem(item);

    Character enemy_matthias;
    enemy_matthias.initCharacter("Matthias", 50, 71);
    item.initItem((Item &) enemy_matthias, "C++ Buch", 1000);
    enemy_matthias.addInventoryItem(item);
    item.initItem((Item &) enemy_matthias, "Magischer Compiler", 1001);
    enemy_matthias.addInventoryItem(item);


    Character enemy_pascal;
    enemy_pascal.initCharacter("Pascal", 100, 27);
    item.initItem((Item &) enemy_pascal, "Mathe Wissenstrank", 10000);
    enemy_pascal.addInventoryItem(item);
    item.initItem((Item &) enemy_pascal, "Taschenrechner", 5);
    enemy_pascal.addInventoryItem(item);


    if(annina.fight(annina, enemy_matthias)){
        cout << enemy_matthias.getCharacterName(enemy_matthias) << " fiel in Ohnmacht! " << annina.getHeroName(annina) << " hat noch " << annina.getHealthPoints(annina) << " Lebenspunkte uebrig!" << endl;
        //annina.getAllItems(annina, enemy_matthias);
        annina.getRandomItem(annina, enemy_matthias);
    }
    else{
        cout << annina.getHeroName(annina) << " fiel in Ohnmacht!" << endl;
        return 0;
    }


    if(annina.fight(annina, enemy_pascal)){
        cout << enemy_pascal.getCharacterName(enemy_pascal) << " fiel in Ohnmacht! " << annina.getHeroName(annina) << " hat noch " << annina.getHealthPoints(annina) << " Lebenspunkte uebrig!" << endl;
        //annina.getAllItems(annina, enemy_pascal);
        annina.getRandomItem(annina, enemy_pascal);
    }
    else{
        cout << annina.getHeroName(annina) << " fiel in Ohnmacht!" << endl;
        return 0;
    }


    for( int i = 0; i < 10; i++ ){
        annina.sellWonItems(annina, i);
    }

    return 0;
}
