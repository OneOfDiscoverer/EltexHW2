BIN := main
SOURCES := main.c command.c 
HEADERS := main.h command.h 
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