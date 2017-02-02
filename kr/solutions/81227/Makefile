RM := rm -f

SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%,$(SRC))

CFLAGS += -std=c11
ifdef DEBUG
CFLAGS += -g -Og
else
CFLAGS += -g
endif

.PHONY: all test testclean clean

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

test: all
	./test

testclean:
	$(RM) foo bar baz wat *.out

clean: testclean
	$(RM) $(BIN)
