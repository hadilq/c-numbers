#ifndef C_FLOAT_36_28_H
#define C_FLOAT_36_28_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_36_28 36
#define EXPONENT_BITS_F_36_28 28
#define BITS_F_36_28 SIGNIFICAND_BITS_F_36_28 + EXPONENT_BITS_F_36_28

#define C_FLOAT_36_28_DEBUG true

typedef uint64_t f3628_t;

#define SIGNIFICAND_MASK_F_36_28 ((1ULL << SIGNIFICAND_BITS_F_36_28) - 1)
#define SIGNIFICAND_2_MASK_F_36_28 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_36_28) - 1)
#define EXPONENT_MASK_F_36_28 (((1ULL << EXPONENT_BITS_F_36_28) - 1) << SIGNIFICAND_BITS_F_36_28)
#define SIGNIFICAND_SIGN_MASK_F_36_28 (1ULL << (SIGNIFICAND_BITS_F_36_28 - 1))
#define EXPONENT_SIGN_MASK_F_36_28 (1ULL << (EXPONENT_BITS_F_36_28 - 1))
#define BITS_SIGN_MASK_F_36_28 (1ULL << (BITS_F_36_28 - 1))

#define MAX_VALUE_F_36_28 (((1ULL << (EXPONENT_BITS_F_36_28 - 2)) - 1) << SIGNIFICAND_BITS_F_36_28) | ((1ULL << (SIGNIFICAND_BITS_F_36_28 - 2)) - 1)
#define MIN_VALUE_F_36_28 (((1ULL << (EXPONENT_BITS_F_36_28 - 2)) - 1) << SIGNIFICAND_BITS_F_36_28) | (SIGNIFICAND_SIGN_MASK_F_36_28)

// construct float 3628
f3628_t new_f3628(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 3628
f3628_t new_f3628_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 3628
f3628_t new_f3628_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 3628
f3628_t new_f3628_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 3628
int64_t exp_f3628(f3628_t a);
// significand part of float 3628
int64_t sig_f3628(f3628_t a);
// add float 3628
f3628_t add_f3628(f3628_t a, f3628_t b);
// subtract float 3628
f3628_t sub_f3628(f3628_t a, f3628_t b);
// negate float 3628
f3628_t neg_f3628(f3628_t a);
// multiply float 3628
f3628_t mul_f3628(f3628_t a, f3628_t b);
// divide float 3628
f3628_t div_f3628(f3628_t a, f3628_t b);
// equals float 3628
bool equ_f3628(f3628_t a, f3628_t b);
// compare float 3628
int com_f3628(f3628_t a, f3628_t b);

#endif // C_FLOAT_36_28_H

