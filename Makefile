CC = gcc
CFLAGS = -g -Wall
BIN = stack-lang
SRC = *.c
OBJ = $(SRC:.c=.o)

.PHONY: clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o $(BIN)
