#!/usr/bin/env nix-shell
#!nix-shell -i bash -p "bc"

function generate_for {
  bits="$1"
  format_bit="$(printf "%02d" "$bits")"
  find generator -type f -regex ".*$bits\.[ch]" | while read -r file; do
    file_name=$(basename "$file")
    init=$(echo "x = l($bits)/l(2) + 1; scale = 0; x / 1" | bc -l)
    init_significand=$((bits - init))
    #finish=$((bits - init))
    finish=$((init + 2))
    for exponent in $(seq "$init" "$finish"); do
      significand=$((bits - exponent))
      format_exponent="$(printf "%02d" "$exponent")"
      format_significand="$(printf "%02d" "$significand")"
      generate_file_name=$(echo "$file_name" | sed -r "s/$format_bit/$format_significand\_$format_exponent/g")
      if [[ $file_name == "test_"* ]]; then
        generate_file="test/$generate_file_name"
      else
        generate_file="src/$generate_file_name"
      fi

      echo "generate_file: $generate_file"
      sed -e "s/CCC_$format_bit $init_significand/CCC_$format_bit $significand/g" < "$file" | \
      	sed -e "s/CCC_$format_bit $init/CCC_$format_bit $exponent/g" | \
      	sed -e "s/_$format_bit.h/_$format_significand\_$format_exponent.h/g" | \
      	sed -e "s/CCC_$format_bit/$format_significand\_$format_exponent/g" | \
      	sed -e "s/DDD$format_bit/$format_significand$format_exponent/g" \
      	> "$generate_file"
    done
  done
}

generate_for 64
generate_for 32
generate_for 16
generate_for 8

# Generate root Makefile
echo "generate_file: Makefile"
cat <<EOF > Makefile
###############################################################################
#
# Numbers in C
#
###############################################################################

TARGET_ARCH ?= \$(shell uname -m)

Makefile:
.PHONY: all clean test

all: lib test_prog

lib:
	\$(MAKE) -C src

test_prog: lib
	\$(MAKE) -C test

test: test_prog
EOF

for file in test/test_*.c; do
    file_name=$(basename "$file")
    task_name=$(echo "$file_name" | sed -r 's/\.c//g' | sed -r 's/_//g')
    echo "	./test/$task_name.a" >> Makefile
done
echo "" >> Makefile

{
  echo "clean:"
  echo "	\$(MAKE) -C src clean"
  echo "	\$(MAKE) -C test clean"
  echo ""
} >> Makefile

# Generate src Makefile
echo "generate_file: src/Makefile"
cat <<EOF > src/Makefile
################################################################################
#
# Makefile sources
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2
EOF

all_tasks=""
for file in src/*.h; do
  file_name=$(basename "$file")
  task_name=$(echo "$file_name" | sed -r 's/\.h//g' | sed -r 's/_//g')
  all_tasks="$all_tasks lib$task_name.a"
done
{
  echo "all: $all_tasks"
  echo ""
} >> src/Makefile

for file in src/*.h; do
  file_name=$(basename "$file")
  prefix_file_name=$(echo "$file_name" | sed -r 's/.h//g')
  task_name=$(echo "$prefix_file_name" | sed -r 's/_//g')

  {
    echo "lib$task_name.a: $task_name.o"
    echo "	ar rcs \$@ $^"
    echo ""

    echo "$task_name.o: $prefix_file_name.c $prefix_file_name.h"
    echo "	\$(CC) \$(CFLAGS) -c $< -o \$@"
    echo ""
  } >> src/Makefile
done

{
  echo "clean:"
  echo "	rm -f *.o *.a"
  echo ""
} >> src/Makefile

# Generate test Makefile
echo "generate_file: test/Makefile"
cat <<EOF > test/Makefile
################################################################################
#
# Makefile test
#
################################################################################

CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2 -I../src
EOF

test_ldflags="LDFLAGS = -L../src "
for file in src/*.h; do
  file_name=$(basename "$file")
  task_name=$(echo "$file_name" | sed -r 's/\.h//g' | sed -r 's/_//g')
  test_ldflags="$test_ldflags -l$task_name"
done

{
  echo "$test_ldflags"
  echo ""
} >> test/Makefile

all_tasks=""
for file in test/*.c; do
  file_name=$(basename "$file")
  task_name=$(echo "$file_name" | sed -r 's/\.c//g'| sed -r 's/_//g')
  all_tasks="$all_tasks $task_name.a"
done
{
  echo "all: $all_tasks"
  echo ""
} >> test/Makefile

for file in test/*.c; do
  file_name=$(basename "$file")
  prefix_file_name=$(echo "$file_name" | sed -r 's/\.c//g')
  task_name=$(echo "$prefix_file_name" | sed -r 's/_//g')
  src_file_name=$(echo "$prefix_file_name" | sed -r 's/test_//g' | sed -r 's/_//g')

  {
    echo "$task_name.a: $task_name.o ../src/lib$src_file_name.a"
    echo "	\$(CC) \$(CFLAGS) $< -o \$@ \$(LDFLAGS)"
    echo ""

    echo "$task_name.o: $prefix_file_name.c"
    echo "	\$(CC) \$(CFLAGS) -c $< -o \$@"
    echo ""
  } >> test/Makefile
done

{
  echo "clean:"
  echo "	rm -f *.o *.a"
  echo ""
} >> test/Makefile

