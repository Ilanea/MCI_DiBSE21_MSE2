#include <iostream>
#include <ctime>
#include "character.h"

using namespace std;


int main() {

    srand(time(nullptr));

    Hero hero;
    Character enemy_matthias;
    Character enemy_pascal;
    Item item;

    Hero annina;
    hero.initHero("Annina", 300, 90);
    item.initItem("Zauberstab", 1000);
    hero.addEquipmentItem(item);

    Character matthias;
    enemy_matthias.initCharacter("Matthias", 50, 71);
    item.initItem("C++ Buch", 1000);
    enemy_matthias.addInventoryItem(item);
    item.initItem("Magischer Compiler", 1001);
    enemy_matthias.addInventoryItem(item);


    Character pascal;
    enemy_pascal.initCharacter("Pascal", 100, 27);
    item.initItem("Mathe Wissenstrank", 10000);
    enemy_pascal.addInventoryItem(item);
    item.initItem("Taschenrechner", 5);
    enemy_pascal.addInventoryItem(item);


    if(hero.fight(hero, enemy_matthias)){
        cout << enemy_matthias.getCharacterName(enemy_matthias) << " fiel in Ohnmacht! " << hero.getHeroName(hero) << " hat noch " << hero.getHealthPoints(hero) << " Lebenspunkte uebrig!" << endl;
        //hero.getAllItems(hero, enemy);
        hero.getRandomItem(hero, enemy_matthias);
    }
    else{
        cout << hero.getHeroName(hero) << " fiel in Ohnmacht!" << endl;
        return 0;
    }


    if(hero.fight(hero, enemy_pascal)){
        cout << enemy_pascal.getCharacterName(enemy_pascal) << " fiel in Ohnmacht! " << hero.getHeroName(hero) << " hat noch " << hero.getHealthPoints(hero) << " Lebenspunkte uebrig!" << endl;
        //hero.getAllItems(hero, enemy);
        hero.getRandomItem(hero, enemy_pascal);
    }
    else{
        cout << hero.getHeroName(hero) << " fiel in Ohnmacht!" << endl;
        return 0;
    }


    for( int i = 0; i < 10; i++ ){
        hero.sellWonItems(annina, i);
    }

    return 0;
}
