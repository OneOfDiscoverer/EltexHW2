BIN := basic
SOURCES := basic.c
HEADERS := basic.h
CFLAGS := 
LDFLAGS :=


CC := gcc

.PHONY: clean

all: $(BIN) 

$LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

$(BIN):$(SOURCES)
		$(CC) -fPIC -c $(SOURCES)
		$(CC) -shared -o lib$(BIN).so $(BIN).o
		rm -rf $(BIN).o

clean:
		rm -rf $(BIN)