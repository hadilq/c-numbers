################################################################################
#
# Makefile sources
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2

all: libcfloat5707.a

libcfloat5707.a: cfloat5707.o
	ar rcs $@ $^

cfloat5707.o: c_float_57_07.c c_float_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

