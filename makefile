CC=gcc
CFLAGS=-Wall -O3
SRC=$(wildcard *.c) 
H_DEPS=$(wildcard *.h) 
DEPS=$(basename ${H_DEPS})
BIN=testbit
# MAINS=main_coal

all: ${BIN}

# ${MAINS}: ${SRC}
# 	$(CC) $(CFLAGS) -o $@ $^ -lm 

%: %.c coales.o 
	$(CC) $(CFLAGS) -o $@ $^ -lm 

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^ 

# clean: 
# 	rm ${TARGETS}

show:
	echo ${SRC}
	# echo ${TARGETS}

.PHONY: all show clean
