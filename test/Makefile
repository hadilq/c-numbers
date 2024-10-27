################################################################################
#
# Makefile test
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2 -I../src
LDFLAGS = -L../src -lcfloat5707  -lcpadic5707 -lcfloat2606 -lcpadic2606 -lcfloat1105 -lcpadic1105 -lcfloat0404 -lcpadic0404

all: test_c_float_26_06.a test_c_p_adic_57_07.a test_c_float_57_07.a test_c_p_adic_26_06.a test_c_float_11_05.a test_c_p_adic_11_05.a test_c_float_04_04.a test_c_p_adic_04_04.a

test_c_float_57_07.a: test_c_float_57_07.o ../src/libcfloat5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_57_07.a: test_c_p_adic_57_07.o ../src/libcpadic5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_57_07.o: test_c_float_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_57_07.o: test_c_p_adic_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_26_06.a: test_c_float_26_06.o ../src/libcfloat2606.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_26_06.a: test_c_p_adic_26_06.o ../src/libcpadic2606.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_26_06.o: test_c_float_26_06.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_26_06.o: test_c_p_adic_26_06.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_11_05.a: test_c_float_11_05.o ../src/libcfloat1105.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_11_05.a: test_c_p_adic_11_05.o ../src/libcpadic1105.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_11_05.o: test_c_float_11_05.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_11_05.o: test_c_p_adic_11_05.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_float_04_04.a: test_c_float_04_04.o ../src/libcfloat0404.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_p_adic_04_04.a: test_c_p_adic_04_04.o ../src/libcpadic0404.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

test_c_float_04_04.o: test_c_float_04_04.c
	$(CC) $(CFLAGS) -c $< -o $@

test_c_p_adic_04_04.o: test_c_p_adic_04_04.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

