CFLAGS = -pedantic -Wextra -Werror

all: A-A clean

A-A: main.o Atomized_Automation_game.o Player.o Texture_Manager.o Map.o
	@echo "Compiling final run file"
	@g++ $(CFLAGS) -g Atomized_Automation_game.o Map.o Player.o Texture_Manager.o  main.o -w -lSDL2 -lSDL2_image -o A-A
	@chmod +X A-A

main.o: main.cpp
	@echo "Compliling main file"
	@g++ $(CFLAGS) -c main.cpp

Atomized_Automation_game.o: Atomized_Automation_game.cpp
	@echo "Compliling game file"
	@g++ $(CFLAGS) -c Atomized_Automation_game.cpp

Map.o: Map.cpp
	@echo "Compiling map config"
	@g++ $(CFLAGS) -c Map.cpp

Player.o: Player.cpp
	@echo "Compiling player file"
	@g++ $(CFLAGS) -c Player.cpp

Enemies.o: Enemies.cpp
	@echo "Compiling enemies file"
	@g++ $(CFLAGS) -c Enemies.cpp

Texture_Manager.o: Texture_Manager.cpp
	@echo "Compiling texture manager"
	g++ $(CFLAGS) -c Texture_Manager.cpp

clean: 
	@echo "Cleaning up files"
	@rm *.o
