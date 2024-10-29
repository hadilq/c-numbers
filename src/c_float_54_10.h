#ifndef C_FLOAT_54_10_H
#define C_FLOAT_54_10_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_54_10 54
#define EXPONENT_BITS_F_54_10 10
#define BITS_F_54_10 SIGNIFICAND_BITS_F_54_10 + EXPONENT_BITS_F_54_10

#define C_FLOAT_54_10_DEBUG true

typedef uint64_t f5410_t;

#define SIGNIFICAND_MASK_F_54_10 ((1ULL << SIGNIFICAND_BITS_F_54_10) - 1)
#define SIGNIFICAND_2_MASK_F_54_10 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_54_10) - 1)
#define EXPONENT_MASK_F_54_10 (((1ULL << EXPONENT_BITS_F_54_10) - 1) << SIGNIFICAND_BITS_F_54_10)
#define SIGNIFICAND_SIGN_MASK_F_54_10 (1ULL << (SIGNIFICAND_BITS_F_54_10 - 1))
#define EXPONENT_SIGN_MASK_F_54_10 (1ULL << (EXPONENT_BITS_F_54_10 - 1))
#define BITS_SIGN_MASK_F_54_10 (1ULL << (BITS_F_54_10 - 1))

#define MAX_VALUE_F_54_10 (((1ULL << (EXPONENT_BITS_F_54_10 - 2)) - 1) << SIGNIFICAND_BITS_F_54_10) | ((1ULL << (SIGNIFICAND_BITS_F_54_10 - 2)) - 1)
#define MIN_VALUE_F_54_10 (((1ULL << (EXPONENT_BITS_F_54_10 - 2)) - 1) << SIGNIFICAND_BITS_F_54_10) | (SIGNIFICAND_SIGN_MASK_F_54_10)

// construct float 5410
f5410_t new_f5410(int64_t exp, int64_t sig);
// construct float 5410
f5410_t new_f5410_from_float64(_Float64 f);
// construct float 5410
f5410_t new_f5410_from_float32(_Float32 f);
// construct float 5410
f5410_t new_f5410_from_float16(_Float16 f);
// exponent part of float 5410
int64_t exp_f5410(f5410_t a);
// significand part of float 5410
int64_t sig_f5410(f5410_t a);
// add float 5410
f5410_t add_f5410(f5410_t a, f5410_t b);
// subtract float 5410
f5410_t sub_f5410(f5410_t a, f5410_t b);
// negate float 5410
f5410_t neg_f5410(f5410_t a);
// multiply float 5410
f5410_t mul_f5410(f5410_t a, f5410_t b);
// divide float 5410
f5410_t div_f5410(f5410_t a, f5410_t b);
// equals float 5410
bool equ_f5410(f5410_t a, f5410_t b);
// compare float 5410
int com_f5410(f5410_t a, f5410_t b);

#endif // C_FLOAT_54_10_H

