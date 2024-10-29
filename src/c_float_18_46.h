#ifndef C_FLOAT_18_46_H
#define C_FLOAT_18_46_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_18_46 18
#define EXPONENT_BITS_F_18_46 46
#define BITS_F_18_46 SIGNIFICAND_BITS_F_18_46 + EXPONENT_BITS_F_18_46

#define C_FLOAT_18_46_DEBUG true

typedef uint64_t f1846_t;

#define SIGNIFICAND_MASK_F_18_46 ((1ULL << SIGNIFICAND_BITS_F_18_46) - 1)
#define SIGNIFICAND_2_MASK_F_18_46 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_18_46) - 1)
#define EXPONENT_MASK_F_18_46 (((1ULL << EXPONENT_BITS_F_18_46) - 1) << SIGNIFICAND_BITS_F_18_46)
#define SIGNIFICAND_SIGN_MASK_F_18_46 (1ULL << (SIGNIFICAND_BITS_F_18_46 - 1))
#define EXPONENT_SIGN_MASK_F_18_46 (1ULL << (EXPONENT_BITS_F_18_46 - 1))
#define BITS_SIGN_MASK_F_18_46 (1ULL << (BITS_F_18_46 - 1))

#define MAX_VALUE_F_18_46 (((1ULL << (EXPONENT_BITS_F_18_46 - 2)) - 1) << SIGNIFICAND_BITS_F_18_46) | ((1ULL << (SIGNIFICAND_BITS_F_18_46 - 2)) - 1)
#define MIN_VALUE_F_18_46 (((1ULL << (EXPONENT_BITS_F_18_46 - 2)) - 1) << SIGNIFICAND_BITS_F_18_46) | (SIGNIFICAND_SIGN_MASK_F_18_46)

// construct float 1846
f1846_t new_f1846(int64_t exp, int64_t sig);
// construct float 1846
f1846_t new_f1846_from_float64(_Float64 f);
// construct float 1846
f1846_t new_f1846_from_float32(_Float32 f);
// construct float 1846
f1846_t new_f1846_from_float16(_Float16 f);
// exponent part of float 1846
int64_t exp_f1846(f1846_t a);
// significand part of float 1846
int64_t sig_f1846(f1846_t a);
// add float 1846
f1846_t add_f1846(f1846_t a, f1846_t b);
// subtract float 1846
f1846_t sub_f1846(f1846_t a, f1846_t b);
// negate float 1846
f1846_t neg_f1846(f1846_t a);
// multiply float 1846
f1846_t mul_f1846(f1846_t a, f1846_t b);
// divide float 1846
f1846_t div_f1846(f1846_t a, f1846_t b);
// equals float 1846
bool equ_f1846(f1846_t a, f1846_t b);
// compare float 1846
int com_f1846(f1846_t a, f1846_t b);

#endif // C_FLOAT_18_46_H

