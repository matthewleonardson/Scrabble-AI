OBJECTS = src/main.o src/tilebag.o src/game.o src/dictionary.o src/board.o           
EXEC = ScrabbleAI.exe
FLAGS = -Wall                                                         
CC = g++                                                              

all: $(OBJECTS)                                                    
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)

.PHONY: clean
clean:
	-rm *.o $(OBJECTS) 