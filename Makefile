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

test: test_prog
	./test/testcfloat0206.a
	./test/testcfloat0404.a
	./test/testcfloat1105.a
	./test/testcfloat2606.a
	./test/testcfloat5707.a
	./test/testcpadic0404.a
	./test/testcpadic1105.a
	./test/testcpadic2606.a
	./test/testcpadic5707.a

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean

