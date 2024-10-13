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
	./test/test_c_float_57_07.a
	./test/test_c_p_adic_57_07.a
	./test/test_c_float_26_06.a
	./test/test_c_p_adic_26_06.a

