#ifndef C_FLOAT_29_35_H
#define C_FLOAT_29_35_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_29_35 29
#define EXPONENT_BITS_F_29_35 35
#define BITS_F_29_35 SIGNIFICAND_BITS_F_29_35 + EXPONENT_BITS_F_29_35

#define C_FLOAT_29_35_DEBUG true

typedef uint64_t f2935_t;

#define SIGNIFICAND_MASK_F_29_35 ((1ULL << SIGNIFICAND_BITS_F_29_35) - 1)
#define SIGNIFICAND_2_MASK_F_29_35 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_29_35) - 1)
#define EXPONENT_MASK_F_29_35 (((1ULL << EXPONENT_BITS_F_29_35) - 1) << SIGNIFICAND_BITS_F_29_35)
#define SIGNIFICAND_SIGN_MASK_F_29_35 (1ULL << (SIGNIFICAND_BITS_F_29_35 - 1))
#define EXPONENT_SIGN_MASK_F_29_35 (1ULL << (EXPONENT_BITS_F_29_35 - 1))
#define BITS_SIGN_MASK_F_29_35 (1ULL << (BITS_F_29_35 - 1))

#define MAX_VALUE_F_29_35 (((1ULL << (EXPONENT_BITS_F_29_35 - 2)) - 1) << SIGNIFICAND_BITS_F_29_35) | ((1ULL << (SIGNIFICAND_BITS_F_29_35 - 2)) - 1)
#define MIN_VALUE_F_29_35 (((1ULL << (EXPONENT_BITS_F_29_35 - 2)) - 1) << SIGNIFICAND_BITS_F_29_35) | (SIGNIFICAND_SIGN_MASK_F_29_35)

// construct float 2935
f2935_t new_f2935(int64_t exp, int64_t sig);
// construct float 2935
f2935_t new_f2935_from_float64(_Float64 f);
// construct float 2935
f2935_t new_f2935_from_float32(_Float32 f);
// construct float 2935
f2935_t new_f2935_from_float16(_Float16 f);
// exponent part of float 2935
int64_t exp_f2935(f2935_t a);
// significand part of float 2935
int64_t sig_f2935(f2935_t a);
// add float 2935
f2935_t add_f2935(f2935_t a, f2935_t b);
// subtract float 2935
f2935_t sub_f2935(f2935_t a, f2935_t b);
// negate float 2935
f2935_t neg_f2935(f2935_t a);
// multiply float 2935
f2935_t mul_f2935(f2935_t a, f2935_t b);
// divide float 2935
f2935_t div_f2935(f2935_t a, f2935_t b);
// equals float 2935
bool equ_f2935(f2935_t a, f2935_t b);
// compare float 2935
int com_f2935(f2935_t a, f2935_t b);

#endif // C_FLOAT_29_35_H

