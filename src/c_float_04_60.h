#ifndef C_FLOAT_04_60_H
#define C_FLOAT_04_60_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_04_60 4
#define EXPONENT_BITS_F_04_60 60
#define BITS_F_04_60 SIGNIFICAND_BITS_F_04_60 + EXPONENT_BITS_F_04_60

#define C_FLOAT_04_60_DEBUG true

typedef uint64_t f0460_t;

#define SIGNIFICAND_MASK_F_04_60 ((1ULL << SIGNIFICAND_BITS_F_04_60) - 1)
#define SIGNIFICAND_2_MASK_F_04_60 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_04_60) - 1)
#define EXPONENT_MASK_F_04_60 (((1ULL << EXPONENT_BITS_F_04_60) - 1) << SIGNIFICAND_BITS_F_04_60)
#define SIGNIFICAND_SIGN_MASK_F_04_60 (1ULL << (SIGNIFICAND_BITS_F_04_60 - 1))
#define EXPONENT_SIGN_MASK_F_04_60 (1ULL << (EXPONENT_BITS_F_04_60 - 1))
#define BITS_SIGN_MASK_F_04_60 (1ULL << (BITS_F_04_60 - 1))

#define MAX_VALUE_F_04_60 (((1ULL << (EXPONENT_BITS_F_04_60 - 2)) - 1) << SIGNIFICAND_BITS_F_04_60) | ((1ULL << (SIGNIFICAND_BITS_F_04_60 - 2)) - 1)
#define MIN_VALUE_F_04_60 (((1ULL << (EXPONENT_BITS_F_04_60 - 2)) - 1) << SIGNIFICAND_BITS_F_04_60) | (SIGNIFICAND_SIGN_MASK_F_04_60)

// construct float 0460
f0460_t new_f0460(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float64)
// construct float 0460
f0460_t new_f0460_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 0460
f0460_t new_f0460_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 0460
f0460_t new_f0460_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 0460
int64_t exp_f0460(f0460_t a);
// significand part of float 0460
int64_t sig_f0460(f0460_t a);
// add float 0460
f0460_t add_f0460(f0460_t a, f0460_t b);
// subtract float 0460
f0460_t sub_f0460(f0460_t a, f0460_t b);
// negate float 0460
f0460_t neg_f0460(f0460_t a);
// multiply float 0460
f0460_t mul_f0460(f0460_t a, f0460_t b);
// divide float 0460
f0460_t div_f0460(f0460_t a, f0460_t b);
// equals float 0460
bool equ_f0460(f0460_t a, f0460_t b);
// compare float 0460
int com_f0460(f0460_t a, f0460_t b);

#endif // C_FLOAT_04_60_H

