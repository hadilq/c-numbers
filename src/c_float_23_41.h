#ifndef C_FLOAT_23_41_H
#define C_FLOAT_23_41_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_23_41 23
#define EXPONENT_BITS_F_23_41 41
#define BITS_F_23_41 SIGNIFICAND_BITS_F_23_41 + EXPONENT_BITS_F_23_41

#define C_FLOAT_23_41_DEBUG true

typedef uint64_t f2341_t;

#define SIGNIFICAND_MASK_F_23_41 ((1ULL << SIGNIFICAND_BITS_F_23_41) - 1)
#define SIGNIFICAND_2_MASK_F_23_41 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_23_41) - 1)
#define EXPONENT_MASK_F_23_41 (((1ULL << EXPONENT_BITS_F_23_41) - 1) << SIGNIFICAND_BITS_F_23_41)
#define SIGNIFICAND_SIGN_MASK_F_23_41 (1ULL << (SIGNIFICAND_BITS_F_23_41 - 1))
#define EXPONENT_SIGN_MASK_F_23_41 (1ULL << (EXPONENT_BITS_F_23_41 - 1))
#define BITS_SIGN_MASK_F_23_41 (1ULL << (BITS_F_23_41 - 1))

#define MAX_VALUE_F_23_41 (((1ULL << (EXPONENT_BITS_F_23_41 - 2)) - 1) << SIGNIFICAND_BITS_F_23_41) | ((1ULL << (SIGNIFICAND_BITS_F_23_41 - 2)) - 1)
#define MIN_VALUE_F_23_41 (((1ULL << (EXPONENT_BITS_F_23_41 - 2)) - 1) << SIGNIFICAND_BITS_F_23_41) | (SIGNIFICAND_SIGN_MASK_F_23_41)

// construct float 2341
f2341_t new_f2341(int64_t exp, int64_t sig);
// construct float 2341
f2341_t new_f2341_from_float64(_Float64 f);
// construct float 2341
f2341_t new_f2341_from_float32(_Float32 f);
// construct float 2341
f2341_t new_f2341_from_float16(_Float16 f);
// exponent part of float 2341
int64_t exp_f2341(f2341_t a);
// significand part of float 2341
int64_t sig_f2341(f2341_t a);
// add float 2341
f2341_t add_f2341(f2341_t a, f2341_t b);
// subtract float 2341
f2341_t sub_f2341(f2341_t a, f2341_t b);
// negate float 2341
f2341_t neg_f2341(f2341_t a);
// multiply float 2341
f2341_t mul_f2341(f2341_t a, f2341_t b);
// divide float 2341
f2341_t div_f2341(f2341_t a, f2341_t b);
// equals float 2341
bool equ_f2341(f2341_t a, f2341_t b);
// compare float 2341
int com_f2341(f2341_t a, f2341_t b);

#endif // C_FLOAT_23_41_H

