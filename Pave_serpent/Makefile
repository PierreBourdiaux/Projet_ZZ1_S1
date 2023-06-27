CC = gcc
CFLAGS = -Wall -Wextra -lm -lSDL2

#repertoire des fichiers communs : eltPile.[ch], eltsArbre.h pile.[ch]
DIRCOMM = ../

#liste des fichiers source
SRC = $(wildcard $(DIRCOMM)*.c *.c)

HEADERS = $(wildcard $(DIRCOMM)*.h *.h)


#liste des fichiers objets
OBJ = $(SRC:%.c=%.o)

pave_serpent: $(OBJ) $(HEADERS)
	$(CC) $(OBJ) -o $@ $(CFLAGS)
	
clean:
	rm -f $(OBJ)
	rm pave_serpent