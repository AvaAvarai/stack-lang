CC     = gcc
CFLAGS = -g -Wall
BIN    = stack-lang
SRCS   = $(wildcard *.c)

.PHONY: clean run

all: $(BIN)

$(BIN): $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	./$(BIN)

clean:
	$(RM) -f $(OBJS) $(BIN) *~
