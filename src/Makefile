# List of object files
OBJS = history.o tokenizer.o 	  	# recursive assignment '=' - evaluated everytime the variable is encountered
OBJS_MAIN := $(OBJS) uimain.o		# Simple assignment ':=' - evaluated only once at its very first occurrence.
OBJS_TEST := $(OBJS) tester.o

CFLAGS=-g -O3

tokenizer.o uimain.o: tokenizer.o
history.o uimain.o: history.h

# user input version 
tokenizer: $(OBJS_MAIN)
	cc -o tokenizer $(CFLAGS) $(OBJS_MAIN)

# Tester.c implementation 
tokenizer_test: $(OBJS_TEST)
	cc -o tokenizer_test $(CFLAGS) $(OBJS_TEST)

all: tokenizer

clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer

test: tokenizer_test
	./tokenizer_test
