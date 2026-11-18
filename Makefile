CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra
LDLIBS = -lcrypto -lm
.PHONY: all run clean
all: cryptolab
cryptolab: src/cryptography_lab.c
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)
run: cryptolab
	./cryptolab
clean:
	rm -f cryptolab
