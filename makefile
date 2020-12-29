
CC = gcc
# CFLAGS = -Wall
CFLAGS =
EXEC = main
OBJ = main.o automateFiniNonDeterministe.o automateFiniDeterministe.o
HEAD = automateFiniNonDeterministe.h automateFiniDeterministe.h constante.h


all: clean $(EXEC) $(OBJ)
	./$(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

main.o: main.c $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)

automateFiniNonDeterministe.o: automateFiniNonDeterministe.c $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)

automateFiniDeterministe.o: automateFiniDeterministe.c $(HEAD)
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	rm -rf *.o
	rm -rf main
