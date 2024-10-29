#ifndef C_FLOAT_41_23_H
#define C_FLOAT_41_23_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_41_23 41
#define EXPONENT_BITS_F_41_23 23
#define BITS_F_41_23 SIGNIFICAND_BITS_F_41_23 + EXPONENT_BITS_F_41_23

#define C_FLOAT_41_23_DEBUG true

typedef uint64_t f4123_t;

#define SIGNIFICAND_MASK_F_41_23 ((1ULL << SIGNIFICAND_BITS_F_41_23) - 1)
#define SIGNIFICAND_2_MASK_F_41_23 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_41_23) - 1)
#define EXPONENT_MASK_F_41_23 (((1ULL << EXPONENT_BITS_F_41_23) - 1) << SIGNIFICAND_BITS_F_41_23)
#define SIGNIFICAND_SIGN_MASK_F_41_23 (1ULL << (SIGNIFICAND_BITS_F_41_23 - 1))
#define EXPONENT_SIGN_MASK_F_41_23 (1ULL << (EXPONENT_BITS_F_41_23 - 1))
#define BITS_SIGN_MASK_F_41_23 (1ULL << (BITS_F_41_23 - 1))

#define MAX_VALUE_F_41_23 (((1ULL << (EXPONENT_BITS_F_41_23 - 2)) - 1) << SIGNIFICAND_BITS_F_41_23) | ((1ULL << (SIGNIFICAND_BITS_F_41_23 - 2)) - 1)
#define MIN_VALUE_F_41_23 (((1ULL << (EXPONENT_BITS_F_41_23 - 2)) - 1) << SIGNIFICAND_BITS_F_41_23) | (SIGNIFICAND_SIGN_MASK_F_41_23)

// construct float 4123
f4123_t new_f4123(int64_t exp, int64_t sig);
// construct float 4123
f4123_t new_f4123_from_float64(_Float64 f);
// construct float 4123
f4123_t new_f4123_from_float32(_Float32 f);
// construct float 4123
f4123_t new_f4123_from_float16(_Float16 f);
// exponent part of float 4123
int64_t exp_f4123(f4123_t a);
// significand part of float 4123
int64_t sig_f4123(f4123_t a);
// add float 4123
f4123_t add_f4123(f4123_t a, f4123_t b);
// subtract float 4123
f4123_t sub_f4123(f4123_t a, f4123_t b);
// negate float 4123
f4123_t neg_f4123(f4123_t a);
// multiply float 4123
f4123_t mul_f4123(f4123_t a, f4123_t b);
// divide float 4123
f4123_t div_f4123(f4123_t a, f4123_t b);
// equals float 4123
bool equ_f4123(f4123_t a, f4123_t b);
// compare float 4123
int com_f4123(f4123_t a, f4123_t b);

#endif // C_FLOAT_41_23_H

