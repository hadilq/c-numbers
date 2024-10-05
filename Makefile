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

