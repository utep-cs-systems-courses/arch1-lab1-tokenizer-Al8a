# List of object files
OBJS = history.o tokenizer.o 	  	# recursive assignment '=' - evaluated everytime the variable is encountered
OBJS_MAIN = $(OBJS) uimain.o		# Simple assignment ':=' - evaluated only once at its very first occurrence.
OBJS_TEST = $(OBJS) tester.o

# Compiler flags -g debug  -O3 optimization 
CFLAGS=-g -O3

#include file dependencies
tokenizer.h: tokenizer.o uimain.o
history.h: history.o uimain.o

# user input implementation 
tokenizer: $(OBJS_MAIN)
	cc -o tokenizer $(CFLAGS) $(OBJS_MAIN)

# Tester.c implementation 
tokenizer_test: $(OBJS_TEST)
	cc -o tokenizer_test $(CFLAGS) $(OBJS_TEST)

all: tokenizer

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# *.h# src

run: tokenizer
	./tokenizer

test: tokenizer_test
	./tokenizer_test
