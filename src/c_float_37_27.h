#ifndef C_FLOAT_37_27_H
#define C_FLOAT_37_27_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_37_27 37
#define EXPONENT_BITS_F_37_27 27
#define BITS_F_37_27 SIGNIFICAND_BITS_F_37_27 + EXPONENT_BITS_F_37_27

#define C_FLOAT_37_27_DEBUG true

typedef uint64_t f3727_t;

#define SIGNIFICAND_MASK_F_37_27 ((1ULL << SIGNIFICAND_BITS_F_37_27) - 1)
#define SIGNIFICAND_2_MASK_F_37_27 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_37_27) - 1)
#define EXPONENT_MASK_F_37_27 (((1ULL << EXPONENT_BITS_F_37_27) - 1) << SIGNIFICAND_BITS_F_37_27)
#define SIGNIFICAND_SIGN_MASK_F_37_27 (1ULL << (SIGNIFICAND_BITS_F_37_27 - 1))
#define EXPONENT_SIGN_MASK_F_37_27 (1ULL << (EXPONENT_BITS_F_37_27 - 1))
#define BITS_SIGN_MASK_F_37_27 (1ULL << (BITS_F_37_27 - 1))

#define MAX_VALUE_F_37_27 (((1ULL << (EXPONENT_BITS_F_37_27 - 2)) - 1) << SIGNIFICAND_BITS_F_37_27) | ((1ULL << (SIGNIFICAND_BITS_F_37_27 - 2)) - 1)
#define MIN_VALUE_F_37_27 (((1ULL << (EXPONENT_BITS_F_37_27 - 2)) - 1) << SIGNIFICAND_BITS_F_37_27) | (SIGNIFICAND_SIGN_MASK_F_37_27)

// construct float 3727
f3727_t new_f3727(int64_t exp, int64_t sig);
// construct float 3727
f3727_t new_f3727_from_float64(_Float64 f);
// construct float 3727
f3727_t new_f3727_from_float32(_Float32 f);
// construct float 3727
f3727_t new_f3727_from_float16(_Float16 f);
// exponent part of float 3727
int64_t exp_f3727(f3727_t a);
// significand part of float 3727
int64_t sig_f3727(f3727_t a);
// add float 3727
f3727_t add_f3727(f3727_t a, f3727_t b);
// subtract float 3727
f3727_t sub_f3727(f3727_t a, f3727_t b);
// negate float 3727
f3727_t neg_f3727(f3727_t a);
// multiply float 3727
f3727_t mul_f3727(f3727_t a, f3727_t b);
// divide float 3727
f3727_t div_f3727(f3727_t a, f3727_t b);
// equals float 3727
bool equ_f3727(f3727_t a, f3727_t b);
// compare float 3727
int com_f3727(f3727_t a, f3727_t b);

#endif // C_FLOAT_37_27_H

