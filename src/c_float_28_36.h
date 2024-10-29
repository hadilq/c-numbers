#ifndef C_FLOAT_28_36_H
#define C_FLOAT_28_36_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_28_36 28
#define EXPONENT_BITS_F_28_36 36
#define BITS_F_28_36 SIGNIFICAND_BITS_F_28_36 + EXPONENT_BITS_F_28_36

#define C_FLOAT_28_36_DEBUG true

typedef uint64_t f2836_t;

#define SIGNIFICAND_MASK_F_28_36 ((1ULL << SIGNIFICAND_BITS_F_28_36) - 1)
#define SIGNIFICAND_2_MASK_F_28_36 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_28_36) - 1)
#define EXPONENT_MASK_F_28_36 (((1ULL << EXPONENT_BITS_F_28_36) - 1) << SIGNIFICAND_BITS_F_28_36)
#define SIGNIFICAND_SIGN_MASK_F_28_36 (1ULL << (SIGNIFICAND_BITS_F_28_36 - 1))
#define EXPONENT_SIGN_MASK_F_28_36 (1ULL << (EXPONENT_BITS_F_28_36 - 1))
#define BITS_SIGN_MASK_F_28_36 (1ULL << (BITS_F_28_36 - 1))

#define MAX_VALUE_F_28_36 (((1ULL << (EXPONENT_BITS_F_28_36 - 2)) - 1) << SIGNIFICAND_BITS_F_28_36) | ((1ULL << (SIGNIFICAND_BITS_F_28_36 - 2)) - 1)
#define MIN_VALUE_F_28_36 (((1ULL << (EXPONENT_BITS_F_28_36 - 2)) - 1) << SIGNIFICAND_BITS_F_28_36) | (SIGNIFICAND_SIGN_MASK_F_28_36)

// construct float 2836
f2836_t new_f2836(int64_t exp, int64_t sig);
// construct float 2836
f2836_t new_f2836_from_float64(_Float64 f);
// construct float 2836
f2836_t new_f2836_from_float32(_Float32 f);
// construct float 2836
f2836_t new_f2836_from_float16(_Float16 f);
// exponent part of float 2836
int64_t exp_f2836(f2836_t a);
// significand part of float 2836
int64_t sig_f2836(f2836_t a);
// add float 2836
f2836_t add_f2836(f2836_t a, f2836_t b);
// subtract float 2836
f2836_t sub_f2836(f2836_t a, f2836_t b);
// negate float 2836
f2836_t neg_f2836(f2836_t a);
// multiply float 2836
f2836_t mul_f2836(f2836_t a, f2836_t b);
// divide float 2836
f2836_t div_f2836(f2836_t a, f2836_t b);
// equals float 2836
bool equ_f2836(f2836_t a, f2836_t b);
// compare float 2836
int com_f2836(f2836_t a, f2836_t b);

#endif // C_FLOAT_28_36_H

