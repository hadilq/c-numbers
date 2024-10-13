################################################################################
#
# Makefile sources
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2

all: libcfloat5707.a libcpadic5707.a libcfloat2606.a libcpadic2606.a

libcfloat5707.a: cfloat5707.o
	ar rcs $@ $^

libcfloat2606.a: cfloat2606.o
	ar rcs $@ $^

libcpadic5707.a: cpadic5707.o
	ar rcs $@ $^

libcpadic2606.a: cpadic2606.o
	ar rcs $@ $^

cfloat5707.o: c_float_57_07.c c_float_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic5707.o: c_p_adic_57_07.c c_p_adic_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat2606.o: c_float_26_06.c c_float_26_06.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic2606.o: c_p_adic_26_06.c c_p_adic_26_06.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

