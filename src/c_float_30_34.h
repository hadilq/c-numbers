#ifndef C_FLOAT_30_34_H
#define C_FLOAT_30_34_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_30_34 30
#define EXPONENT_BITS_F_30_34 34
#define BITS_F_30_34 SIGNIFICAND_BITS_F_30_34 + EXPONENT_BITS_F_30_34

#define C_FLOAT_30_34_DEBUG true

typedef uint64_t f3034_t;

#define SIGNIFICAND_MASK_F_30_34 ((1ULL << SIGNIFICAND_BITS_F_30_34) - 1)
#define SIGNIFICAND_2_MASK_F_30_34 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_30_34) - 1)
#define EXPONENT_MASK_F_30_34 (((1ULL << EXPONENT_BITS_F_30_34) - 1) << SIGNIFICAND_BITS_F_30_34)
#define SIGNIFICAND_SIGN_MASK_F_30_34 (1ULL << (SIGNIFICAND_BITS_F_30_34 - 1))
#define EXPONENT_SIGN_MASK_F_30_34 (1ULL << (EXPONENT_BITS_F_30_34 - 1))
#define BITS_SIGN_MASK_F_30_34 (1ULL << (BITS_F_30_34 - 1))

#define MAX_VALUE_F_30_34 (((1ULL << (EXPONENT_BITS_F_30_34 - 2)) - 1) << SIGNIFICAND_BITS_F_30_34) | ((1ULL << (SIGNIFICAND_BITS_F_30_34 - 2)) - 1)
#define MIN_VALUE_F_30_34 (((1ULL << (EXPONENT_BITS_F_30_34 - 2)) - 1) << SIGNIFICAND_BITS_F_30_34) | (SIGNIFICAND_SIGN_MASK_F_30_34)

// construct float 3034
f3034_t new_f3034(int64_t exp, int64_t sig);
// construct float 3034
f3034_t new_f3034_from_float64(_Float64 f);
// construct float 3034
f3034_t new_f3034_from_float32(_Float32 f);
// construct float 3034
f3034_t new_f3034_from_float16(_Float16 f);
// exponent part of float 3034
int64_t exp_f3034(f3034_t a);
// significand part of float 3034
int64_t sig_f3034(f3034_t a);
// add float 3034
f3034_t add_f3034(f3034_t a, f3034_t b);
// subtract float 3034
f3034_t sub_f3034(f3034_t a, f3034_t b);
// negate float 3034
f3034_t neg_f3034(f3034_t a);
// multiply float 3034
f3034_t mul_f3034(f3034_t a, f3034_t b);
// divide float 3034
f3034_t div_f3034(f3034_t a, f3034_t b);
// equals float 3034
bool equ_f3034(f3034_t a, f3034_t b);
// compare float 3034
int com_f3034(f3034_t a, f3034_t b);

#endif // C_FLOAT_30_34_H

