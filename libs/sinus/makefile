BIN := sinus
SOURCES := sinus.c
HEADERS := sinus.h
CFLAGS := -c
LDFLAGS := -lm


CC := gcc

.PHONY: clean

all: $(BIN) 

$LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

$(BIN):$(SOURCES)
		$(CC) -fPIC $(CFLAGS) $(SOURCES)
		$(CC) -shared -o lib$(BIN).so $(BIN).o $(LDFLAGS)
		rm -rf $(BIN).o
		mv lib$(BIN).so ./..

clean:
		rm -rf $(BIN)