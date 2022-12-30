CC     = gcc
CFLAGS = -g -Wall
BIN    = stack-lang
SRCS   = $(wildcard *.c)

.PHONY: clean

all: $(BIN)

$(BIN): $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) -f $(OBJS) $(BIN) *~
