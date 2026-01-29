CC = gcc
CFLAGS = -Wall -Wextra
OPENSSL_INCLUDE = $(shell brew --prefix openssl@3 2>/dev/null || brew --prefix openssl 2>/dev/null || echo /usr/local/opt/openssl)/include
OPENSSL_LIB = $(shell brew --prefix openssl@3 2>/dev/null || brew --prefix openssl 2>/dev/null || echo /usr/local/opt/openssl)/lib
LDFLAGS = -L$(OPENSSL_LIB) -lssl -lcrypto

TARGET = passchecker
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -I$(OPENSSL_INCLUDE) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
