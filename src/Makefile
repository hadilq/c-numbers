################################################################################
#
# Makefile sources
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2

all: libcfloat5707.a libcpadic5707.a libcfloat2606.a libcpadic2606.a libcfloat1105.a libcpadic1105.a libcfloat0404.a libcpadic0404.a

libcfloat5707.a: cfloat5707.o
	ar rcs $@ $^

libcpadic5707.a: cpadic5707.o
	ar rcs $@ $^

libcfloat2606.a: cfloat2606.o
	ar rcs $@ $^

libcpadic2606.a: cpadic2606.o
	ar rcs $@ $^

libcfloat1105.a: cfloat1105.o
	ar rcs $@ $^

libcpadic1105.a: cpadic1105.o
	ar rcs $@ $^

libcfloat0404.a: cfloat0404.o
	ar rcs $@ $^

libcpadic0404.a: cpadic0404.o
	ar rcs $@ $^

cfloat5707.o: c_float_57_07.c c_float_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic5707.o: c_p_adic_57_07.c c_p_adic_57_07.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat2606.o: c_float_26_06.c c_float_26_06.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic2606.o: c_p_adic_26_06.c c_p_adic_26_06.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat1105.o: c_float_11_05.c c_float_11_05.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic1105.o: c_p_adic_11_05.c c_p_adic_11_05.h
	$(CC) $(CFLAGS) -c $< -o $@

cfloat0404.o: c_float_04_04.c c_float_04_04.h
	$(CC) $(CFLAGS) -c $< -o $@

cpadic0404.o: c_p_adic_04_04.c c_p_adic_04_04.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a

