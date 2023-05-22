BIN := main
SOURCES := main.c command.c libs/basic.c
HEADERS := main.h command.h libs/basic.h
CFLAGS := -g
LDFLAGS :=


CC := gcc

.PHONY: clean

all: $(BIN) 

$LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

$(BIN): $(SOURCES)
		$(CC) $(SOURCES) -o $(BIN) $(CFLAGS) $(LDFLAGS)
$(BIN): $(HEADERS)

clean:
		rm -rf $(BIN)