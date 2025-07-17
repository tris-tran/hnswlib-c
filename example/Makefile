CC = gcc
CFLAGS = -O2 -std=c11 -pthread
INCLUDES = -I../
LIBNAME = libhnsw.a
OBJS = bindings.o

all: example

example: example.c 
	$(CC) $(CFLAGS) $(INCLUDES) $< -L.. -lm -lhnsw -lstdc++ -o $@

clean:
	rm -f *.o *.a example

.PHONY: all clean
