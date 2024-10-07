################################################################################
#
# Makefile sources
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=gnu99 -O2

all: libcfloat5707.a libcpadic5707.a

libcfloat5707.a: cfloat5707.o
	ar rcs $@ $^

libcpadic5707.a: cpadic5707.o
	ar rcs $@ $^

cfloat5707.o: c_float_57_07.c c_float_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic5707.o: c_p_adic_57_07.c c_p_adic_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

