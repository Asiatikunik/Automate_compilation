
CC = gcc
CFLAGS = -Wall
EXEC = main
OBJ = main.o automateFiniNonDeterministe.o
HEAD = automateFiniNonDeterministe.h


all: clean $(EXEC) $(OBJ)
	./$(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

main.o: main.c $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)

automateFiniNonDeterministe.o: automateFiniNonDeterministe.c $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	rm -rf *.o
	rm -rf main
