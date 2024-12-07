CC = gcc
CFLAGS = -g

OBJECT = obj
SRC = src
MAIN = main

$(MAIN): $(OBJECT)/main.o $(OBJECT)/celdas.o $(OBJECT)/comandos.o
	$(CC) $(OBJECT)/main.o $(OBJECT)/celdas.o $(OBJECT)/comandos.o -o $(TARGET)

$(OBJECT)/main.o: $(SRC)/main.c incl/celdas.h incl/comandos.h
	$(CC) $(CFLAGS) -c $(SRC)/main.c -o $(OBJECT)/main.o

$(OBJECT)/celdas.o: $(SRC)/celdas.c incl/celdas.h
	$(CC) $(CFLAGS) -c $(SRC)/celdas.c -o $(OBJECT)/celdas.o

$(OBJECT)/comandos.o: $(SRC)/comandos.c incl/comandos.h
	$(CC) $(CFLAGS) -c $(SRC)/comandos.c -o $(OBJECT)/comandos.o

clean:
	rm -f $(OBJECT)/* $(MAIN)