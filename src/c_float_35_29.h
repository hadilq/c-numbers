#ifndef C_FLOAT_35_29_H
#define C_FLOAT_35_29_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_35_29 35
#define EXPONENT_BITS_F_35_29 29
#define BITS_F_35_29 SIGNIFICAND_BITS_F_35_29 + EXPONENT_BITS_F_35_29

#define C_FLOAT_35_29_DEBUG true

typedef uint64_t f3529_t;

#define SIGNIFICAND_MASK_F_35_29 ((1ULL << SIGNIFICAND_BITS_F_35_29) - 1)
#define SIGNIFICAND_2_MASK_F_35_29 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_35_29) - 1)
#define EXPONENT_MASK_F_35_29 (((1ULL << EXPONENT_BITS_F_35_29) - 1) << SIGNIFICAND_BITS_F_35_29)
#define SIGNIFICAND_SIGN_MASK_F_35_29 (1ULL << (SIGNIFICAND_BITS_F_35_29 - 1))
#define EXPONENT_SIGN_MASK_F_35_29 (1ULL << (EXPONENT_BITS_F_35_29 - 1))
#define BITS_SIGN_MASK_F_35_29 (1ULL << (BITS_F_35_29 - 1))

#define MAX_VALUE_F_35_29 (((1ULL << (EXPONENT_BITS_F_35_29 - 2)) - 1) << SIGNIFICAND_BITS_F_35_29) | ((1ULL << (SIGNIFICAND_BITS_F_35_29 - 2)) - 1)
#define MIN_VALUE_F_35_29 (((1ULL << (EXPONENT_BITS_F_35_29 - 2)) - 1) << SIGNIFICAND_BITS_F_35_29) | (SIGNIFICAND_SIGN_MASK_F_35_29)

// construct float 3529
f3529_t new_f3529(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float64)
// construct float 3529
f3529_t new_f3529_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 3529
f3529_t new_f3529_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 3529
f3529_t new_f3529_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 3529
int64_t exp_f3529(f3529_t a);
// significand part of float 3529
int64_t sig_f3529(f3529_t a);
// add float 3529
f3529_t add_f3529(f3529_t a, f3529_t b);
// subtract float 3529
f3529_t sub_f3529(f3529_t a, f3529_t b);
// negate float 3529
f3529_t neg_f3529(f3529_t a);
// multiply float 3529
f3529_t mul_f3529(f3529_t a, f3529_t b);
// divide float 3529
f3529_t div_f3529(f3529_t a, f3529_t b);
// equals float 3529
bool equ_f3529(f3529_t a, f3529_t b);
// compare float 3529
int com_f3529(f3529_t a, f3529_t b);

#endif // C_FLOAT_35_29_H

