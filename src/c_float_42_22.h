#ifndef C_FLOAT_42_22_H
#define C_FLOAT_42_22_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_42_22 42
#define EXPONENT_BITS_F_42_22 22
#define BITS_F_42_22 SIGNIFICAND_BITS_F_42_22 + EXPONENT_BITS_F_42_22

#define C_FLOAT_42_22_DEBUG true

typedef uint64_t f4222_t;

#define SIGNIFICAND_MASK_F_42_22 ((1ULL << SIGNIFICAND_BITS_F_42_22) - 1)
#define SIGNIFICAND_2_MASK_F_42_22 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_42_22) - 1)
#define EXPONENT_MASK_F_42_22 (((1ULL << EXPONENT_BITS_F_42_22) - 1) << SIGNIFICAND_BITS_F_42_22)
#define SIGNIFICAND_SIGN_MASK_F_42_22 (1ULL << (SIGNIFICAND_BITS_F_42_22 - 1))
#define EXPONENT_SIGN_MASK_F_42_22 (1ULL << (EXPONENT_BITS_F_42_22 - 1))
#define BITS_SIGN_MASK_F_42_22 (1ULL << (BITS_F_42_22 - 1))

#define MAX_VALUE_F_42_22 (((1ULL << (EXPONENT_BITS_F_42_22 - 2)) - 1) << SIGNIFICAND_BITS_F_42_22) | ((1ULL << (SIGNIFICAND_BITS_F_42_22 - 2)) - 1)
#define MIN_VALUE_F_42_22 (((1ULL << (EXPONENT_BITS_F_42_22 - 2)) - 1) << SIGNIFICAND_BITS_F_42_22) | (SIGNIFICAND_SIGN_MASK_F_42_22)

// construct float 4222
f4222_t new_f4222(int64_t exp, int64_t sig);
// construct float 4222
f4222_t new_f4222_from_float64(_Float64 f);
// construct float 4222
f4222_t new_f4222_from_float32(_Float32 f);
// construct float 4222
f4222_t new_f4222_from_float16(_Float16 f);
// exponent part of float 4222
int64_t exp_f4222(f4222_t a);
// significand part of float 4222
int64_t sig_f4222(f4222_t a);
// add float 4222
f4222_t add_f4222(f4222_t a, f4222_t b);
// subtract float 4222
f4222_t sub_f4222(f4222_t a, f4222_t b);
// negate float 4222
f4222_t neg_f4222(f4222_t a);
// multiply float 4222
f4222_t mul_f4222(f4222_t a, f4222_t b);
// divide float 4222
f4222_t div_f4222(f4222_t a, f4222_t b);
// equals float 4222
bool equ_f4222(f4222_t a, f4222_t b);
// compare float 4222
int com_f4222(f4222_t a, f4222_t b);

#endif // C_FLOAT_42_22_H

