#ifndef C_FLOAT_56_08_H
#define C_FLOAT_56_08_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_56_08 56
#define EXPONENT_BITS_F_56_08 8
#define BITS_F_56_08 SIGNIFICAND_BITS_F_56_08 + EXPONENT_BITS_F_56_08

#define C_FLOAT_56_08_DEBUG true

typedef uint64_t f5608_t;

#define SIGNIFICAND_MASK_F_56_08 ((1ULL << SIGNIFICAND_BITS_F_56_08) - 1)
#define SIGNIFICAND_2_MASK_F_56_08 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_56_08) - 1)
#define EXPONENT_MASK_F_56_08 (((1ULL << EXPONENT_BITS_F_56_08) - 1) << SIGNIFICAND_BITS_F_56_08)
#define SIGNIFICAND_SIGN_MASK_F_56_08 (1ULL << (SIGNIFICAND_BITS_F_56_08 - 1))
#define EXPONENT_SIGN_MASK_F_56_08 (1ULL << (EXPONENT_BITS_F_56_08 - 1))
#define BITS_SIGN_MASK_F_56_08 (1ULL << (BITS_F_56_08 - 1))

#define MAX_VALUE_F_56_08 (((1ULL << (EXPONENT_BITS_F_56_08 - 2)) - 1) << SIGNIFICAND_BITS_F_56_08) | ((1ULL << (SIGNIFICAND_BITS_F_56_08 - 2)) - 1)
#define MIN_VALUE_F_56_08 (((1ULL << (EXPONENT_BITS_F_56_08 - 2)) - 1) << SIGNIFICAND_BITS_F_56_08) | (SIGNIFICAND_SIGN_MASK_F_56_08)

// construct float 5608
f5608_t new_f5608(int64_t exp, int64_t sig);
// construct float 5608
f5608_t new_f5608_from_float64(_Float64 f);
// construct float 5608
f5608_t new_f5608_from_float32(_Float32 f);
// construct float 5608
f5608_t new_f5608_from_float16(_Float16 f);
// exponent part of float 5608
int64_t exp_f5608(f5608_t a);
// significand part of float 5608
int64_t sig_f5608(f5608_t a);
// add float 5608
f5608_t add_f5608(f5608_t a, f5608_t b);
// subtract float 5608
f5608_t sub_f5608(f5608_t a, f5608_t b);
// negate float 5608
f5608_t neg_f5608(f5608_t a);
// multiply float 5608
f5608_t mul_f5608(f5608_t a, f5608_t b);
// divide float 5608
f5608_t div_f5608(f5608_t a, f5608_t b);
// equals float 5608
bool equ_f5608(f5608_t a, f5608_t b);
// compare float 5608
int com_f5608(f5608_t a, f5608_t b);

#endif // C_FLOAT_56_08_H

