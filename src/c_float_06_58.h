#ifndef C_FLOAT_06_58_H
#define C_FLOAT_06_58_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_06_58 6
#define EXPONENT_BITS_F_06_58 58
#define BITS_F_06_58 SIGNIFICAND_BITS_F_06_58 + EXPONENT_BITS_F_06_58

#define C_FLOAT_06_58_DEBUG true

typedef uint64_t f0658_t;

#define SIGNIFICAND_MASK_F_06_58 ((1ULL << SIGNIFICAND_BITS_F_06_58) - 1)
#define SIGNIFICAND_2_MASK_F_06_58 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_06_58) - 1)
#define EXPONENT_MASK_F_06_58 (((1ULL << EXPONENT_BITS_F_06_58) - 1) << SIGNIFICAND_BITS_F_06_58)
#define SIGNIFICAND_SIGN_MASK_F_06_58 (1ULL << (SIGNIFICAND_BITS_F_06_58 - 1))
#define EXPONENT_SIGN_MASK_F_06_58 (1ULL << (EXPONENT_BITS_F_06_58 - 1))
#define BITS_SIGN_MASK_F_06_58 (1ULL << (BITS_F_06_58 - 1))

#define MAX_VALUE_F_06_58 (((1ULL << (EXPONENT_BITS_F_06_58 - 2)) - 1) << SIGNIFICAND_BITS_F_06_58) | ((1ULL << (SIGNIFICAND_BITS_F_06_58 - 2)) - 1)
#define MIN_VALUE_F_06_58 (((1ULL << (EXPONENT_BITS_F_06_58 - 2)) - 1) << SIGNIFICAND_BITS_F_06_58) | (SIGNIFICAND_SIGN_MASK_F_06_58)

// construct float 0658
f0658_t new_f0658(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 0658
f0658_t new_f0658_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0658
f0658_t new_f0658_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0658
f0658_t new_f0658_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 0658
int64_t exp_f0658(f0658_t a);
// significand part of float 0658
int64_t sig_f0658(f0658_t a);
// add float 0658
f0658_t add_f0658(f0658_t a, f0658_t b);
// subtract float 0658
f0658_t sub_f0658(f0658_t a, f0658_t b);
// negate float 0658
f0658_t neg_f0658(f0658_t a);
// multiply float 0658
f0658_t mul_f0658(f0658_t a, f0658_t b);
// divide float 0658
f0658_t div_f0658(f0658_t a, f0658_t b);
// equals float 0658
bool equ_f0658(f0658_t a, f0658_t b);
// compare float 0658
int com_f0658(f0658_t a, f0658_t b);

#endif // C_FLOAT_06_58_H

