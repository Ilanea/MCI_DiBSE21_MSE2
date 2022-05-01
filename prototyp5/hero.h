//
// Created by msyu on 21.03.2022.
//

#ifndef PROTOTYP5_HERO_H
#define PROTOTYP5_HERO_H


#include <cstring>
#include "item.h"
#include "character.h"
#include "fighter.h"
#include "sorcerer.h"

class Hero : public Character
{
public:

    using Character::Character;

    //Destruktor
    ~Hero() {
        std::cout << "Unsere Heldin " << this->Name << " verabschiedet sich vom Spiel und reitet in den Sonnenuntergang!" << std::endl;
    }

    void attack(Hero &hero, Character &enemy) override;
    bool fight(Hero &hero, Character &enemy);
    void retrieveAllLoot(Hero &hero, Character &enemy);
    std::shared_ptr<Item> retrieveRandomLoot(Hero &hero, Character &enemy);
    void sellAllItems(Hero &hero);
    void sellLootItems(Hero &hero);

};

#endif //PROTOTYP5_HERO_H
