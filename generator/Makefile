###############################################################################
#
# Numbers in C
#
###############################################################################

TARGET_ARCH ?= $(shell uname -m)

Makefile:
.PHONY: all clean test

all: lib test_prog

lib:
	$(MAKE) -C src

test_prog: lib
	$(MAKE) -C test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean

test: test_prog
	./test/test_c_float_64.a
	./test/test_c_p_adic_64.a
	./test/test_c_float_32.a
	./test/test_c_p_adic_32.a
	./test/test_c_float_16.a
	./test/test_c_p_adic_16.a
	./test/test_c_float_08.a
	./test/test_c_p_adic_08.a

