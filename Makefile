CC = gcc
STD = -std=c17
OPTIMIZE = -O3
LIBS = -lraylib -lm 
WARN = -Wall
LIBPATH = -L./lib

game_of_life : main.c *.o
	$(CC) $^ -o $@ $(LIBS) $(LIBPATH) $(OPTIMIZE) $(STD) $(WARN)

*.o : src/*.c
	$(CC) $^ -c $(OPTIMIZE) $(STD)

clean :
	rm *.o
	rm game_of_life
