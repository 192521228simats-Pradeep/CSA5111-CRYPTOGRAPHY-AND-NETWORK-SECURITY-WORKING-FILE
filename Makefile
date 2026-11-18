CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra
.PHONY: all run clean
all: cryptolab
cryptolab: cryptography_lab.c
	$(CC) $(CFLAGS) $< -o $@
run: cryptolab
	./cryptolab
clean:
	rm -f cryptolab
