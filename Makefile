CC = gcc
CFLAGS = -g -Wall
TARGET = stack

.PHONY: clean

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
