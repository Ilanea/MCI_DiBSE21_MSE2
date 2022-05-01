//
// Created by msyu on 30.04.2022.
//

#ifndef PROTOTYP5_GAME_H
#define PROTOTYP5_GAME_H

#include <map>
#include <vector>
#include <memory>

class Character;
class Item;


class Game {

private:
    std::map<std::string, std::shared_ptr<Character>> Characters;
    std::vector<std::shared_ptr<Item>> Items;

public:
    Game(){};

    ~Game(){
      Characters.clear();
    };

    void play();
    void createCharacter(std::shared_ptr<Character> Character);
    void destroyCharacter(std::string Name);
    void createItem(const std::shared_ptr<Item>& Item);

};

#endif //PROTOTYP5_GAME_H
