#ifndef C_FLOAT_19_45_H
#define C_FLOAT_19_45_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_19_45 19
#define EXPONENT_BITS_F_19_45 45
#define BITS_F_19_45 SIGNIFICAND_BITS_F_19_45 + EXPONENT_BITS_F_19_45

#define C_FLOAT_19_45_DEBUG true

typedef uint64_t f1945_t;

#define SIGNIFICAND_MASK_F_19_45 ((1ULL << SIGNIFICAND_BITS_F_19_45) - 1)
#define SIGNIFICAND_2_MASK_F_19_45 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_19_45) - 1)
#define EXPONENT_MASK_F_19_45 (((1ULL << EXPONENT_BITS_F_19_45) - 1) << SIGNIFICAND_BITS_F_19_45)
#define SIGNIFICAND_SIGN_MASK_F_19_45 (1ULL << (SIGNIFICAND_BITS_F_19_45 - 1))
#define EXPONENT_SIGN_MASK_F_19_45 (1ULL << (EXPONENT_BITS_F_19_45 - 1))
#define BITS_SIGN_MASK_F_19_45 (1ULL << (BITS_F_19_45 - 1))

#define MAX_VALUE_F_19_45 (((1ULL << (EXPONENT_BITS_F_19_45 - 2)) - 1) << SIGNIFICAND_BITS_F_19_45) | ((1ULL << (SIGNIFICAND_BITS_F_19_45 - 2)) - 1)
#define MIN_VALUE_F_19_45 (((1ULL << (EXPONENT_BITS_F_19_45 - 2)) - 1) << SIGNIFICAND_BITS_F_19_45) | (SIGNIFICAND_SIGN_MASK_F_19_45)

// construct float 1945
f1945_t new_f1945(int64_t exp, int64_t sig);
// construct float 1945
f1945_t new_f1945_from_float64(_Float64 f);
// construct float 1945
f1945_t new_f1945_from_float32(_Float32 f);
// construct float 1945
f1945_t new_f1945_from_float16(_Float16 f);
// exponent part of float 1945
int64_t exp_f1945(f1945_t a);
// significand part of float 1945
int64_t sig_f1945(f1945_t a);
// add float 1945
f1945_t add_f1945(f1945_t a, f1945_t b);
// subtract float 1945
f1945_t sub_f1945(f1945_t a, f1945_t b);
// negate float 1945
f1945_t neg_f1945(f1945_t a);
// multiply float 1945
f1945_t mul_f1945(f1945_t a, f1945_t b);
// divide float 1945
f1945_t div_f1945(f1945_t a, f1945_t b);
// equals float 1945
bool equ_f1945(f1945_t a, f1945_t b);
// compare float 1945
int com_f1945(f1945_t a, f1945_t b);

#endif // C_FLOAT_19_45_H

