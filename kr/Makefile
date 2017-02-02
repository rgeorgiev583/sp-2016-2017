SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%,$(SRC))

CFLAGS += -std=c11
ifdef DEBUG
CFLAGS += -g -Og
else
CFLAGS += -g
endif

.PHONY: all testclean clean

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

testclean:
	$(RM) foo bar baz wat *.out

clean: testclean
	$(RM) $(BIN)
