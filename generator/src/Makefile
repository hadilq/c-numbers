################################################################################
#
# Makefile sources
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2

all: libcfloat64.a libcpadic64.a libcfloat32.a libcpadic32.a libcfloat16.a libcpadic16.a libcfloat08.a libcpadic08.a

libcfloat64.a: cfloat64.o
	ar rcs $@ $^

libcpadic64.a: cpadic64.o
	ar rcs $@ $^

libcfloat32.a: cfloat32.o
	ar rcs $@ $^

libcpadic32.a: cpadic32.o
	ar rcs $@ $^

libcfloat16.a: cfloat16.o
	ar rcs $@ $^

libcpadic16.a: cpadic16.o
	ar rcs $@ $^

libcfloat08.a: cfloat08.o
	ar rcs $@ $^

libcpadic08.a: cpadic08.o
	ar rcs $@ $^

cfloat64.o: c_float_64.c c_float_64.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic64.o: c_p_adic_64.c c_p_adic_64.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat32.o: c_float_32.c c_float_32.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic32.o: c_p_adic_32.c c_p_adic_32.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat16.o: c_float_16.c c_float_16.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic16.o: c_p_adic_16.c c_p_adic_16.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat08.o: c_float_08.c c_float_08.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic08.o: c_p_adic_08.c c_p_adic_08.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

