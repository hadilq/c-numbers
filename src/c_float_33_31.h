#ifndef C_FLOAT_33_31_H
#define C_FLOAT_33_31_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_33_31 33
#define EXPONENT_BITS_F_33_31 31
#define BITS_F_33_31 SIGNIFICAND_BITS_F_33_31 + EXPONENT_BITS_F_33_31

#define C_FLOAT_33_31_DEBUG true

typedef uint64_t f3331_t;

#define SIGNIFICAND_MASK_F_33_31 ((1ULL << SIGNIFICAND_BITS_F_33_31) - 1)
#define SIGNIFICAND_2_MASK_F_33_31 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_33_31) - 1)
#define EXPONENT_MASK_F_33_31 (((1ULL << EXPONENT_BITS_F_33_31) - 1) << SIGNIFICAND_BITS_F_33_31)
#define SIGNIFICAND_SIGN_MASK_F_33_31 (1ULL << (SIGNIFICAND_BITS_F_33_31 - 1))
#define EXPONENT_SIGN_MASK_F_33_31 (1ULL << (EXPONENT_BITS_F_33_31 - 1))
#define BITS_SIGN_MASK_F_33_31 (1ULL << (BITS_F_33_31 - 1))

#define MAX_VALUE_F_33_31 (((1ULL << (EXPONENT_BITS_F_33_31 - 2)) - 1) << SIGNIFICAND_BITS_F_33_31) | ((1ULL << (SIGNIFICAND_BITS_F_33_31 - 2)) - 1)
#define MIN_VALUE_F_33_31 (((1ULL << (EXPONENT_BITS_F_33_31 - 2)) - 1) << SIGNIFICAND_BITS_F_33_31) | (SIGNIFICAND_SIGN_MASK_F_33_31)

// construct float 3331
f3331_t new_f3331(int64_t exp, int64_t sig);
// construct float 3331
f3331_t new_f3331_from_float64(_Float64 f);
// construct float 3331
f3331_t new_f3331_from_float32(_Float32 f);
// construct float 3331
f3331_t new_f3331_from_float16(_Float16 f);
// exponent part of float 3331
int64_t exp_f3331(f3331_t a);
// significand part of float 3331
int64_t sig_f3331(f3331_t a);
// add float 3331
f3331_t add_f3331(f3331_t a, f3331_t b);
// subtract float 3331
f3331_t sub_f3331(f3331_t a, f3331_t b);
// negate float 3331
f3331_t neg_f3331(f3331_t a);
// multiply float 3331
f3331_t mul_f3331(f3331_t a, f3331_t b);
// divide float 3331
f3331_t div_f3331(f3331_t a, f3331_t b);
// equals float 3331
bool equ_f3331(f3331_t a, f3331_t b);
// compare float 3331
int com_f3331(f3331_t a, f3331_t b);

#endif // C_FLOAT_33_31_H

