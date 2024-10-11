################################################################################
#
# Makefile test
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2 -I../src
LDFLAGS = -L../src -lcfloat5707 -lcpadic5707

all: test_c_float_57_07.a test_c_p_adic_57_07.a

test_c_float_57_07.a: test_c_float_57_07.o ../src/libcfloat5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_57_07.a: test_c_p_adic_57_07.o ../src/libcpadic5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_57_07.o: test_c_float_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_57_07.o: test_c_p_adic_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

