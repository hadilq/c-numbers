#ifndef C_FLOAT_52_12_H
#define C_FLOAT_52_12_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_52_12 52
#define EXPONENT_BITS_F_52_12 12
#define BITS_F_52_12 SIGNIFICAND_BITS_F_52_12 + EXPONENT_BITS_F_52_12

#define C_FLOAT_52_12_DEBUG true

typedef uint64_t f5212_t;

#define SIGNIFICAND_MASK_F_52_12 ((1ULL << SIGNIFICAND_BITS_F_52_12) - 1)
#define SIGNIFICAND_2_MASK_F_52_12 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_52_12) - 1)
#define EXPONENT_MASK_F_52_12 (((1ULL << EXPONENT_BITS_F_52_12) - 1) << SIGNIFICAND_BITS_F_52_12)
#define SIGNIFICAND_SIGN_MASK_F_52_12 (1ULL << (SIGNIFICAND_BITS_F_52_12 - 1))
#define EXPONENT_SIGN_MASK_F_52_12 (1ULL << (EXPONENT_BITS_F_52_12 - 1))
#define BITS_SIGN_MASK_F_52_12 (1ULL << (BITS_F_52_12 - 1))

#define MAX_VALUE_F_52_12 (((1ULL << (EXPONENT_BITS_F_52_12 - 2)) - 1) << SIGNIFICAND_BITS_F_52_12) | ((1ULL << (SIGNIFICAND_BITS_F_52_12 - 2)) - 1)
#define MIN_VALUE_F_52_12 (((1ULL << (EXPONENT_BITS_F_52_12 - 2)) - 1) << SIGNIFICAND_BITS_F_52_12) | (SIGNIFICAND_SIGN_MASK_F_52_12)

// construct float 5212
f5212_t new_f5212(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float64)
// construct float 5212
f5212_t new_f5212_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 5212
f5212_t new_f5212_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 5212
f5212_t new_f5212_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 5212
int64_t exp_f5212(f5212_t a);
// significand part of float 5212
int64_t sig_f5212(f5212_t a);
// add float 5212
f5212_t add_f5212(f5212_t a, f5212_t b);
// subtract float 5212
f5212_t sub_f5212(f5212_t a, f5212_t b);
// negate float 5212
f5212_t neg_f5212(f5212_t a);
// multiply float 5212
f5212_t mul_f5212(f5212_t a, f5212_t b);
// divide float 5212
f5212_t div_f5212(f5212_t a, f5212_t b);
// equals float 5212
bool equ_f5212(f5212_t a, f5212_t b);
// compare float 5212
int com_f5212(f5212_t a, f5212_t b);

#endif // C_FLOAT_52_12_H

