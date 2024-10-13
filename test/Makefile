################################################################################
#
# Makefile test
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2 -I../src
LDFLAGS = -L../src -lcfloat5707 -lcfloat2606 -lcpadic5707 -lcpadic2606

all: test_c_float_26_06.a test_c_float_57_07.a test_c_p_adic_57_07.a test_c_p_adic_26_06.a

test_c_float_57_07.a: test_c_float_57_07.o ../src/libcfloat5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_57_07.a: test_c_p_adic_57_07.o ../src/libcpadic5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_26_06.a: test_c_float_26_06.o ../src/libcfloat2606.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_26_06.a: test_c_p_adic_26_06.o ../src/libcpadic2606.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_57_07.o: test_c_float_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_26_06.o: test_c_float_26_06.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_57_07.o: test_c_p_adic_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_26_06.o: test_c_p_adic_26_06.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

