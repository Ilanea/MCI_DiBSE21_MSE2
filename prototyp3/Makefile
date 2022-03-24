prototyp: main.o hero.o character.o item.o npc.o fighter.o sorcerer.o
	g++ -o prototyp3 main.o hero.o character.o item.o npc.o fighter.o sorcerer.o
    
main.o: main.cpp
	g++ -c -o main.o main.cpp
    
character.o: character.cpp character.h
	g++ -c -o character.o character.cpp
    
hero.o: hero.cpp hero.h
	g++ -c -o hero.o hero.cpp
    
item.o: item.cpp item.h
	g++ -c -o item.o item.cpp

npc.o: npc.cpp npc.h
	g++ -c -o npc.o npc.cpp

fighter.o: fighter.cpp fighter.h
	g++ -c -o fighter.o fighter.cpp
    
sorcerer.o: sorcerer.cpp sorcerer.h
	g++ -c -o sorcerer.o sorcerer.cpp

clean:
	rm -rf item.o hero.o character.o npc.o fighter.o sorcerer.o main.o