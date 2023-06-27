CC = gcc
CFLAGS = -Wall -Wextra -lm -lSDL2 -lSDL2_image

#repertoire des fichiers communs 
DIRCOMM = ../

#liste des fichiers source
SRC = $(wildcard $(DIRCOMM)*.c *.c)

HEADERS = $(wildcard $(DIRCOMM)*.h *.h)


#liste des fichiers objets
OBJ = $(SRC:%.c=%.o)

Animation: $(OBJ) $(HEADERS)
	$(CC) $(OBJ) -o $@ $(CFLAGS)
	
clean:
	rm -f $(OBJ)
	rm Animation