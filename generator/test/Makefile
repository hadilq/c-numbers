################################################################################
#
# Makefile test
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2 -I../src
LDFLAGS = -L../src -lcfloat64  -lcpadic64 -lcfloat32 -lcpadic32 -lcfloat16 -lcpadic16 -lcfloat08 -lcpadic08

all: test_c_float_64.a test_c_p_adic_64.a test_c_float_32.a test_c_p_adic_32.a test_c_float_16.a test_c_p_adic_16.a test_c_float_08.a test_c_p_adic_08.a

test_c_float_64.a: test_c_float_64.o ../src/libcfloat64.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_64.a: test_c_p_adic_64.o ../src/libcpadic64.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_64.o: test_c_float_64.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_64.o: test_c_p_adic_64.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_32.a: test_c_float_32.o ../src/libcfloat32.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_32.a: test_c_p_adic_32.o ../src/libcpadic32.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_32.o: test_c_float_32.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_32.o: test_c_p_adic_32.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_16.a: test_c_float_16.o ../src/libcfloat16.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_16.a: test_c_p_adic_16.o ../src/libcpadic16.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_16.o: test_c_float_16.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_16.o: test_c_p_adic_16.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_08.a: test_c_float_08.o ../src/libcfloat08.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_08.a: test_c_p_adic_08.o ../src/libcpadic08.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_08.o: test_c_float_08.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_08.o: test_c_p_adic_08.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

