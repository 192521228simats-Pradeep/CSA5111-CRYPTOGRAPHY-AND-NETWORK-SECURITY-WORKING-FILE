CC ?= gcc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wno-unused-function -Wno-unused-variable
LDLIBS ?= -lcrypto -lm
QUESTIONS := $(foreach n,$(shell seq -w 1 40),Q$(n))
.PHONY: all clean help $(QUESTIONS)
all: $(QUESTIONS)

Q%: Q%.c common/crypto_common.h
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o bin/$@ $(LDLIBS)

help:
	@echo "make all | make Q22 | ./bin/Q22 | make clean"
clean:
	rm -rf bin
