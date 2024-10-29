#ifndef C_FLOAT_47_17_H
#define C_FLOAT_47_17_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_47_17 47
#define EXPONENT_BITS_F_47_17 17
#define BITS_F_47_17 SIGNIFICAND_BITS_F_47_17 + EXPONENT_BITS_F_47_17

#define C_FLOAT_47_17_DEBUG true

typedef uint64_t f4717_t;

#define SIGNIFICAND_MASK_F_47_17 ((1ULL << SIGNIFICAND_BITS_F_47_17) - 1)
#define SIGNIFICAND_2_MASK_F_47_17 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_47_17) - 1)
#define EXPONENT_MASK_F_47_17 (((1ULL << EXPONENT_BITS_F_47_17) - 1) << SIGNIFICAND_BITS_F_47_17)
#define SIGNIFICAND_SIGN_MASK_F_47_17 (1ULL << (SIGNIFICAND_BITS_F_47_17 - 1))
#define EXPONENT_SIGN_MASK_F_47_17 (1ULL << (EXPONENT_BITS_F_47_17 - 1))
#define BITS_SIGN_MASK_F_47_17 (1ULL << (BITS_F_47_17 - 1))

#define MAX_VALUE_F_47_17 (((1ULL << (EXPONENT_BITS_F_47_17 - 2)) - 1) << SIGNIFICAND_BITS_F_47_17) | ((1ULL << (SIGNIFICAND_BITS_F_47_17 - 2)) - 1)
#define MIN_VALUE_F_47_17 (((1ULL << (EXPONENT_BITS_F_47_17 - 2)) - 1) << SIGNIFICAND_BITS_F_47_17) | (SIGNIFICAND_SIGN_MASK_F_47_17)

// construct float 4717
f4717_t new_f4717(int64_t exp, int64_t sig);
// construct float 4717
f4717_t new_f4717_from_float64(_Float64 f);
// construct float 4717
f4717_t new_f4717_from_float32(_Float32 f);
// construct float 4717
f4717_t new_f4717_from_float16(_Float16 f);
// exponent part of float 4717
int64_t exp_f4717(f4717_t a);
// significand part of float 4717
int64_t sig_f4717(f4717_t a);
// add float 4717
f4717_t add_f4717(f4717_t a, f4717_t b);
// subtract float 4717
f4717_t sub_f4717(f4717_t a, f4717_t b);
// negate float 4717
f4717_t neg_f4717(f4717_t a);
// multiply float 4717
f4717_t mul_f4717(f4717_t a, f4717_t b);
// divide float 4717
f4717_t div_f4717(f4717_t a, f4717_t b);
// equals float 4717
bool equ_f4717(f4717_t a, f4717_t b);
// compare float 4717
int com_f4717(f4717_t a, f4717_t b);

#endif // C_FLOAT_47_17_H

