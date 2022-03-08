prototyp: main.o hero.o character.o item.o
	g++ -o prototyp2 main.o hero.o character.o item.o
    
main.o: main.cpp
	g++ -c -o main.o main.cpp
    
character.o: character.cpp character.h
	g++ -c -o character.o character.cpp
    
hero.o: hero.cpp hero.h
	g++ -c -o hero.o hero.cpp
    
item.o: item.cpp item.h
	g++ -c -o item.o item.cpp
    
clean:
	rm -rf item.o	hero.o	character.o	main.o