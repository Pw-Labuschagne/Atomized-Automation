CFLAGS = -pedantic -Wextra -Werror

all: A_A_Run clean

A_A_Run: A_A.o Texture_Manager.o
	@echo "Compiling final run file"
	@gcc $(CFLAGS) A_A.o Texture_Manager.o -w -lSDL2 -lSDL2_image -o A_A_Run
	@chmod +X A_A_Run

A_A.o: A_A.c
	@echo "Compliling main file"
	@gcc $(CLFAGS) -c A_A.c

A_A_player.o: A_A_player.c
	@echo "Compiling player file"
	@gcc $(CFLAGS) -c A_A_player.c

A_A_enemies.o: A_A_enemies.c
	@echo "Compiling enemies file"
	@gcc $(CFLAGS) -c A_A_enemies.c

Texture_Manager.o: Texture_Manager.c
	@echo "Compiling texture manager"
	gcc $(CFLAGS) -c Texture_Manager.c

clean: 
	@echo "Cleaning up files"
	@rm *.o
