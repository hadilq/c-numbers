#ifndef C_FLOAT_31_33_H
#define C_FLOAT_31_33_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_31_33 31
#define EXPONENT_BITS_F_31_33 33
#define BITS_F_31_33 SIGNIFICAND_BITS_F_31_33 + EXPONENT_BITS_F_31_33

#define C_FLOAT_31_33_DEBUG true

typedef uint64_t f3133_t;

#define SIGNIFICAND_MASK_F_31_33 ((1ULL << SIGNIFICAND_BITS_F_31_33) - 1)
#define SIGNIFICAND_2_MASK_F_31_33 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_31_33) - 1)
#define EXPONENT_MASK_F_31_33 (((1ULL << EXPONENT_BITS_F_31_33) - 1) << SIGNIFICAND_BITS_F_31_33)
#define SIGNIFICAND_SIGN_MASK_F_31_33 (1ULL << (SIGNIFICAND_BITS_F_31_33 - 1))
#define EXPONENT_SIGN_MASK_F_31_33 (1ULL << (EXPONENT_BITS_F_31_33 - 1))
#define BITS_SIGN_MASK_F_31_33 (1ULL << (BITS_F_31_33 - 1))

#define MAX_VALUE_F_31_33 (((1ULL << (EXPONENT_BITS_F_31_33 - 2)) - 1) << SIGNIFICAND_BITS_F_31_33) | ((1ULL << (SIGNIFICAND_BITS_F_31_33 - 2)) - 1)
#define MIN_VALUE_F_31_33 (((1ULL << (EXPONENT_BITS_F_31_33 - 2)) - 1) << SIGNIFICAND_BITS_F_31_33) | (SIGNIFICAND_SIGN_MASK_F_31_33)

// construct float 3133
f3133_t new_f3133(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 3133
f3133_t new_f3133_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 3133
f3133_t new_f3133_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 3133
f3133_t new_f3133_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 3133
int64_t exp_f3133(f3133_t a);
// significand part of float 3133
int64_t sig_f3133(f3133_t a);
// add float 3133
f3133_t add_f3133(f3133_t a, f3133_t b);
// subtract float 3133
f3133_t sub_f3133(f3133_t a, f3133_t b);
// negate float 3133
f3133_t neg_f3133(f3133_t a);
// multiply float 3133
f3133_t mul_f3133(f3133_t a, f3133_t b);
// divide float 3133
f3133_t div_f3133(f3133_t a, f3133_t b);
// equals float 3133
bool equ_f3133(f3133_t a, f3133_t b);
// compare float 3133
int com_f3133(f3133_t a, f3133_t b);

#endif // C_FLOAT_31_33_H

