//
// Created by msyu on 30.04.2022.
//

#include <iostream>
#include <ctime>
#include <algorithm>
#include "game.h"
#include "hero.h"

void Game::createCharacter(std::shared_ptr<Character> Character){
    if(Characters.find(Character->getName()) == Characters.end()){
        Characters.insert({Character->getName(), Character});
    }
    else{
        throw CharacterAlreadyExists("Game::createCharacter(): Character already exists.");
    }
}

void Game::destroyCharacter(std::string Name){

    if(Characters.find(Name) == Characters.end()){
        throw CharacterDoesNotExists("Game::destroyCharacter(): Character does not exists.");
    }
    else{
        Characters.erase(Name);
    }
}

void Game::createItem(const std::shared_ptr<Item>& Item){
    if(std::find(Items.begin(), Items.end(), Item) != Items.end()){
        Items.push_back(Item);
    }
    else{
        throw ItemAlreadyExists("Game::createItem(): Item already exists.");
    }
}

void Game::play(){

    srand(time(nullptr));


    try{

        std::shared_ptr<Hero> annina(new Hero("Annina", 300, 90, 50, 50));
        createCharacter(annina);
        annina->addEquipmentItem(std::shared_ptr<Item>(new Item((Item &) annina, "Zauberstab", 1000)));

        std::shared_ptr<Fighter> enemy_matthias(new Fighter("Matthias", 50, 71, 10, 5, 50));
        createCharacter(enemy_matthias);
        enemy_matthias->addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_matthias, "C++ Buch", 1000)));
        enemy_matthias->addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_matthias, "Magischer Compiler", 1001)));

        std::shared_ptr<Sorcerer> enemy_pascal(new Sorcerer("Pascal", 100, 27, 15, 5, 50));
        createCharacter(enemy_pascal);
        enemy_pascal->addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_pascal, "Mathe Trank", 10000)));
        enemy_pascal->addInventoryItem(std::shared_ptr<Item>(new Item((Item &) enemy_pascal, "Taschenrechner", 5)));

        std::cout << "---------------------------------- Fight 1 ----------------------------------" << std::endl;

        if(annina->fight(*annina, *enemy_matthias)){
            std::cout << enemy_matthias->getName() << " fiel in Ohnmacht! " << annina->getName() << " hat noch " << annina->getHealthPoints() << " Lebenspunkte uebrig!" << std::endl;
            annina->retrieveRandomLoot(*annina, *enemy_matthias);
            std::cout << "Matthias shared_ptr Count: " << enemy_matthias.use_count() << std::endl;
            destroyCharacter(enemy_matthias->getName());
            enemy_matthias.reset();
        }
        else{
            std::cout << annina->getName() << " fiel in Ohnmacht!" << std::endl;
            destroyCharacter(annina->getName());
            annina.reset();
            return;
        }

        std::cout << "---------------------------------- Fight 2 ----------------------------------" << std::endl;

        if(annina->fight(*annina, *enemy_pascal)){
            std::cout << enemy_pascal->getName() << " fiel in Ohnmacht! " << annina->getName() << " hat noch " << annina->getHealthPoints() << " Lebenspunkte uebrig!" << std::endl;
            annina->retrieveRandomLoot(*annina, *enemy_pascal);
            destroyCharacter(enemy_pascal->getName());
            enemy_pascal.reset();
        }
        else{
            std::cout << annina->getName() << " fiel in Ohnmacht!" << std::endl;
            destroyCharacter(annina->getName());
            annina.reset();
            return;
        }

        std::cout << "---------------------------------- Verkaufen ----------------------------------" << std::endl;

        annina->sellLootItems(*annina);

        std::cout << "---------------------------------- Bye ----------------------------------" << std::endl;
        destroyCharacter(annina->getName());
        annina.reset();


    }  catch (std::exception &error){
        std::cerr << "Exception in Game::Play: " << error.what() << std::endl;
    }

}