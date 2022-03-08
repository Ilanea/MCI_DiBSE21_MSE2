#include <iostream>
#include <ctime>
#include "character.h"
#include "hero.h"
#include "item.h"

using namespace std;


int main() {

    srand(time(nullptr));

    Hero hero;
    Character enemy;
    Character enemy1;
    Item item;

    Hero annina;
    hero.initHero("Annina", 300, 90);
    item.initItem("Zauberstab", 1000);
    hero.addEquipmentItem(item);

    Character matthias;
    enemy.initCharacter("Matthias", 50, 71);
    item.initItem("C++ Buch", 1000);
    enemy.addInventoryItem(item);
    item.initItem("Magischer Compiler", 1001);
    enemy.addInventoryItem(item);


    Character pascal;
    enemy1.initCharacter("Pascal", 100, 27);
    item.initItem("Mathe Wissenstrank", 10000);
    enemy1.addInventoryItem(item);
    item.initItem("Taschenrechner", 5);
    enemy1.addInventoryItem(item);


    if(hero.fight(hero, enemy)){
        cout << enemy.getCharacterName(enemy) << " fiel in Ohnmacht! " << hero.getHeroName(hero) << " hat noch " << hero.getHealthPoints(hero) << " Lebenspunkte uebrig!" << endl;
        //hero.getAllItems(hero, enemy);
        hero.getRandomItem(hero, enemy);
    }
    else{
        cout << hero.getHeroName(hero) << " fiel in Ohnmacht!" << endl;
        return 0;
    }


    if(hero.fight(hero, enemy1)){
        cout << enemy1.getCharacterName(enemy1) << " fiel in Ohnmacht! " << hero.getHeroName(hero) << " hat noch " << hero.getHealthPoints(hero) << " Lebenspunkte uebrig!" << endl;
        //hero.getAllItems(hero, enemy);
        hero.getRandomItem(hero, enemy1);
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
