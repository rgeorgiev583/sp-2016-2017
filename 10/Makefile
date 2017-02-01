RM := rm -f

SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%,$(SRC))

CFLAGS += -std=c11 -pedantic -Wall
ifdef DEBUG
CFLAGS += -g -Og
else
CFLAGS += -O3
endif

.PHONY: all clean

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(BIN)
