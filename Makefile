CC = gcc
STD = -std=c17
OPTIMIZE = -Ofast
LIBS = -lraylib -lm
WARN = -Wall -Werror
LIBPATH = -Llib

game_of_life : *.o
	$(CC) $^ -o $@ $(LIBS) $(LIBPATH) $(OPTIMIZE) $(STD) $(WARN)

*.o : src/*.c main.c
	$(CC) $^ -c $(OPTIMIZE) $(STD)

clean :
	rm *.o
	rm game_of_life
