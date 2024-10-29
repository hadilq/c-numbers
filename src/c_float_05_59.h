#ifndef C_FLOAT_05_59_H
#define C_FLOAT_05_59_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_05_59 5
#define EXPONENT_BITS_F_05_59 59
#define BITS_F_05_59 SIGNIFICAND_BITS_F_05_59 + EXPONENT_BITS_F_05_59

#define C_FLOAT_05_59_DEBUG true

typedef uint64_t f0559_t;

#define SIGNIFICAND_MASK_F_05_59 ((1ULL << SIGNIFICAND_BITS_F_05_59) - 1)
#define SIGNIFICAND_2_MASK_F_05_59 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_05_59) - 1)
#define EXPONENT_MASK_F_05_59 (((1ULL << EXPONENT_BITS_F_05_59) - 1) << SIGNIFICAND_BITS_F_05_59)
#define SIGNIFICAND_SIGN_MASK_F_05_59 (1ULL << (SIGNIFICAND_BITS_F_05_59 - 1))
#define EXPONENT_SIGN_MASK_F_05_59 (1ULL << (EXPONENT_BITS_F_05_59 - 1))
#define BITS_SIGN_MASK_F_05_59 (1ULL << (BITS_F_05_59 - 1))

#define MAX_VALUE_F_05_59 (((1ULL << (EXPONENT_BITS_F_05_59 - 2)) - 1) << SIGNIFICAND_BITS_F_05_59) | ((1ULL << (SIGNIFICAND_BITS_F_05_59 - 2)) - 1)
#define MIN_VALUE_F_05_59 (((1ULL << (EXPONENT_BITS_F_05_59 - 2)) - 1) << SIGNIFICAND_BITS_F_05_59) | (SIGNIFICAND_SIGN_MASK_F_05_59)

// construct float 0559
f0559_t new_f0559(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 0559
f0559_t new_f0559_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0559
f0559_t new_f0559_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0559
f0559_t new_f0559_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 0559
int64_t exp_f0559(f0559_t a);
// significand part of float 0559
int64_t sig_f0559(f0559_t a);
// add float 0559
f0559_t add_f0559(f0559_t a, f0559_t b);
// subtract float 0559
f0559_t sub_f0559(f0559_t a, f0559_t b);
// negate float 0559
f0559_t neg_f0559(f0559_t a);
// multiply float 0559
f0559_t mul_f0559(f0559_t a, f0559_t b);
// divide float 0559
f0559_t div_f0559(f0559_t a, f0559_t b);
// equals float 0559
bool equ_f0559(f0559_t a, f0559_t b);
// compare float 0559
int com_f0559(f0559_t a, f0559_t b);

#endif // C_FLOAT_05_59_H

