CC=gcc
CFLAGS=-W -Wall -Werror -fPIC
LDFLAGS=-L. -l$(LIB) -lm
EXEC=$(DN)
SRC=$(wildcard *.c)
OBJ= $(SRC:*.c=.o)

LIB=ctoolbox
DN=lib$(LIB).so

DN_CFLAGS= -fPIC -shared -Wl,-soname,$(DN)

all: $(EXEC)

$(DN): $(OBJ)
	$(CC) -o $@ $^ $(DN_CFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: mrproper clean rebuild

clean:
	@rm -rf *.o *~

mrproper: clean
	@rm -rf $(EXEC)

rebuild: mrproper all
