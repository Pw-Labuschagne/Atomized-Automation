CFLAGS = -pedantic -Wextra -Werror

all: A-A clean

A-A: main.o Graphics.o Game_Manager.o Timer.o
	@echo "Compiling final run file"
	@g++ $(CFLAGS) Graphics.o Game_Manager.o Timer.o  main.o -w -lSDL2 -lSDL2_image -o A-A -g
	@chmod +X A-A

main.o: main.cpp
	@echo "Compliling main file"
	@g++ $(CFLAGS) -c main.cpp

Graphics.o: Graphics.cpp
	@echo "Compliling Graphics file"
	@g++ $(CFLAGS) -c Graphics.cpp

Timer.o: Timer.cpp
	@echo "Compiling Timer file"
	@g++ $(CFLAGS) -c Timer.cpp

Game_Manager.o: Game_Manager.cpp
	@echo "Compiling Game_Manager file"
	@g++ $(CFLAGS) -c Game_Manager.cpp

clean: 
	@echo "Cleaning up files"
	@rm *.o
