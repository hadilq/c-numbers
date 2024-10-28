################################################################################
#
# Makefile test
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2 -I../src
LDFLAGS = -L../src  -lcfloat0206 -lcfloat0214 -lcfloat0230 -lcfloat0262 -lcfloat0305 -lcfloat0313 -lcfloat0329 -lcfloat0361 -lcfloat0404 -lcfloat0412 -lcfloat0428 -lcfloat0460 -lcfloat0511 -lcfloat0527 -lcfloat0559 -lcfloat0610 -lcfloat0626 -lcfloat0658 -lcfloat0709 -lcfloat0725 -lcfloat0757 -lcfloat0808 -lcfloat0824 -lcfloat0856 -lcfloat0907 -lcfloat0923 -lcfloat0955 -lcfloat1006 -lcfloat1022 -lcfloat1054 -lcfloat1105 -lcfloat1121 -lcfloat1153 -lcfloat1220 -lcfloat1252 -lcfloat1319 -lcfloat1351 -lcfloat1418 -lcfloat1450 -lcfloat1517 -lcfloat1549 -lcfloat1616 -lcfloat1648 -lcfloat1715 -lcfloat1747 -lcfloat1814 -lcfloat1846 -lcfloat1913 -lcfloat1945 -lcfloat2012 -lcfloat2044 -lcfloat2111 -lcfloat2143 -lcfloat2210 -lcfloat2242 -lcfloat2309 -lcfloat2341 -lcfloat2408 -lcfloat2440 -lcfloat2507 -lcfloat2539 -lcfloat2606 -lcfloat2638 -lcfloat2737 -lcfloat2836 -lcfloat2935 -lcfloat3034 -lcfloat3133 -lcfloat3232 -lcfloat3331 -lcfloat3430 -lcfloat3529 -lcfloat3628 -lcfloat3727 -lcfloat3826 -lcfloat3925 -lcfloat4024 -lcfloat4123 -lcfloat4222 -lcfloat4321 -lcfloat4420 -lcfloat4519 -lcfloat4618 -lcfloat4717 -lcfloat4816 -lcfloat4915 -lcfloat5014 -lcfloat5113 -lcfloat5212 -lcfloat5311 -lcfloat5410 -lcfloat5509 -lcfloat5608 -lcfloat5707 -lcpadic0206 -lcpadic0214 -lcpadic0230 -lcpadic0262 -lcpadic0305 -lcpadic0313 -lcpadic0329 -lcpadic0361 -lcpadic0404 -lcpadic0412 -lcpadic0428 -lcpadic0460 -lcpadic0511 -lcpadic0527 -lcpadic0559 -lcpadic0610 -lcpadic0626 -lcpadic0658 -lcpadic0709 -lcpadic0725 -lcpadic0757 -lcpadic0808 -lcpadic0824 -lcpadic0856 -lcpadic0907 -lcpadic0923 -lcpadic0955 -lcpadic1006 -lcpadic1022 -lcpadic1054 -lcpadic1105 -lcpadic1121 -lcpadic1153 -lcpadic1220 -lcpadic1252 -lcpadic1319 -lcpadic1351 -lcpadic1418 -lcpadic1450 -lcpadic1517 -lcpadic1549 -lcpadic1616 -lcpadic1648 -lcpadic1715 -lcpadic1747 -lcpadic1814 -lcpadic1846 -lcpadic1913 -lcpadic1945 -lcpadic2012 -lcpadic2044 -lcpadic2111 -lcpadic2143 -lcpadic2210 -lcpadic2242 -lcpadic2309 -lcpadic2341 -lcpadic2408 -lcpadic2440 -lcpadic2507 -lcpadic2539 -lcpadic2606 -lcpadic2638 -lcpadic2737 -lcpadic2836 -lcpadic2935 -lcpadic3034 -lcpadic3133 -lcpadic3232 -lcpadic3331 -lcpadic3430 -lcpadic3529 -lcpadic3628 -lcpadic3727 -lcpadic3826 -lcpadic3925 -lcpadic4024 -lcpadic4123 -lcpadic4222 -lcpadic4321 -lcpadic4420 -lcpadic4519 -lcpadic4618 -lcpadic4717 -lcpadic4816 -lcpadic4915 -lcpadic5014 -lcpadic5113 -lcpadic5212 -lcpadic5311 -lcpadic5410 -lcpadic5509 -lcpadic5608 -lcpadic5707

all:  testcfloat0206.a testcfloat0404.a testcfloat1105.a testcfloat2606.a testcfloat5707.a testcpadic0404.a testcpadic1105.a testcpadic2606.a testcpadic5707.a

testcfloat0206.a: testcfloat0206.o ../src/libcfloat0206.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcfloat0206.o: test_c_float_02_06.c
	$(CC) $(CFLAGS) -c $< -o $@

testcfloat0404.a: testcfloat0404.o ../src/libcfloat0404.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcfloat0404.o: test_c_float_04_04.c
	$(CC) $(CFLAGS) -c $< -o $@

testcfloat1105.a: testcfloat1105.o ../src/libcfloat1105.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcfloat1105.o: test_c_float_11_05.c
	$(CC) $(CFLAGS) -c $< -o $@

testcfloat2606.a: testcfloat2606.o ../src/libcfloat2606.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcfloat2606.o: test_c_float_26_06.c
	$(CC) $(CFLAGS) -c $< -o $@

testcfloat5707.a: testcfloat5707.o ../src/libcfloat5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcfloat5707.o: test_c_float_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

testcpadic0404.a: testcpadic0404.o ../src/libcpadic0404.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcpadic0404.o: test_c_p_adic_04_04.c
	$(CC) $(CFLAGS) -c $< -o $@

testcpadic1105.a: testcpadic1105.o ../src/libcpadic1105.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcpadic1105.o: test_c_p_adic_11_05.c
	$(CC) $(CFLAGS) -c $< -o $@

testcpadic2606.a: testcpadic2606.o ../src/libcpadic2606.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcpadic2606.o: test_c_p_adic_26_06.c
	$(CC) $(CFLAGS) -c $< -o $@

testcpadic5707.a: testcpadic5707.o ../src/libcpadic5707.a
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

testcpadic5707.o: test_c_p_adic_57_07.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

