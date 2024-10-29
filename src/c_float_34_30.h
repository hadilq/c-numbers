#ifndef C_FLOAT_34_30_H
#define C_FLOAT_34_30_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_34_30 34
#define EXPONENT_BITS_F_34_30 30
#define BITS_F_34_30 SIGNIFICAND_BITS_F_34_30 + EXPONENT_BITS_F_34_30

#define C_FLOAT_34_30_DEBUG true

typedef uint64_t f3430_t;

#define SIGNIFICAND_MASK_F_34_30 ((1ULL << SIGNIFICAND_BITS_F_34_30) - 1)
#define SIGNIFICAND_2_MASK_F_34_30 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_34_30) - 1)
#define EXPONENT_MASK_F_34_30 (((1ULL << EXPONENT_BITS_F_34_30) - 1) << SIGNIFICAND_BITS_F_34_30)
#define SIGNIFICAND_SIGN_MASK_F_34_30 (1ULL << (SIGNIFICAND_BITS_F_34_30 - 1))
#define EXPONENT_SIGN_MASK_F_34_30 (1ULL << (EXPONENT_BITS_F_34_30 - 1))
#define BITS_SIGN_MASK_F_34_30 (1ULL << (BITS_F_34_30 - 1))

#define MAX_VALUE_F_34_30 (((1ULL << (EXPONENT_BITS_F_34_30 - 2)) - 1) << SIGNIFICAND_BITS_F_34_30) | ((1ULL << (SIGNIFICAND_BITS_F_34_30 - 2)) - 1)
#define MIN_VALUE_F_34_30 (((1ULL << (EXPONENT_BITS_F_34_30 - 2)) - 1) << SIGNIFICAND_BITS_F_34_30) | (SIGNIFICAND_SIGN_MASK_F_34_30)

// construct float 3430
f3430_t new_f3430(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float64)
// construct float 3430
f3430_t new_f3430_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 3430
f3430_t new_f3430_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 3430
f3430_t new_f3430_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 3430
int64_t exp_f3430(f3430_t a);
// significand part of float 3430
int64_t sig_f3430(f3430_t a);
// add float 3430
f3430_t add_f3430(f3430_t a, f3430_t b);
// subtract float 3430
f3430_t sub_f3430(f3430_t a, f3430_t b);
// negate float 3430
f3430_t neg_f3430(f3430_t a);
// multiply float 3430
f3430_t mul_f3430(f3430_t a, f3430_t b);
// divide float 3430
f3430_t div_f3430(f3430_t a, f3430_t b);
// equals float 3430
bool equ_f3430(f3430_t a, f3430_t b);
// compare float 3430
int com_f3430(f3430_t a, f3430_t b);

#endif // C_FLOAT_34_30_H

