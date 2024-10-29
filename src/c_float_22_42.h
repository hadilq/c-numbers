#ifndef C_FLOAT_22_42_H
#define C_FLOAT_22_42_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_22_42 22
#define EXPONENT_BITS_F_22_42 42
#define BITS_F_22_42 SIGNIFICAND_BITS_F_22_42 + EXPONENT_BITS_F_22_42

#define C_FLOAT_22_42_DEBUG true

typedef uint64_t f2242_t;

#define SIGNIFICAND_MASK_F_22_42 ((1ULL << SIGNIFICAND_BITS_F_22_42) - 1)
#define SIGNIFICAND_2_MASK_F_22_42 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_22_42) - 1)
#define EXPONENT_MASK_F_22_42 (((1ULL << EXPONENT_BITS_F_22_42) - 1) << SIGNIFICAND_BITS_F_22_42)
#define SIGNIFICAND_SIGN_MASK_F_22_42 (1ULL << (SIGNIFICAND_BITS_F_22_42 - 1))
#define EXPONENT_SIGN_MASK_F_22_42 (1ULL << (EXPONENT_BITS_F_22_42 - 1))
#define BITS_SIGN_MASK_F_22_42 (1ULL << (BITS_F_22_42 - 1))

#define MAX_VALUE_F_22_42 (((1ULL << (EXPONENT_BITS_F_22_42 - 2)) - 1) << SIGNIFICAND_BITS_F_22_42) | ((1ULL << (SIGNIFICAND_BITS_F_22_42 - 2)) - 1)
#define MIN_VALUE_F_22_42 (((1ULL << (EXPONENT_BITS_F_22_42 - 2)) - 1) << SIGNIFICAND_BITS_F_22_42) | (SIGNIFICAND_SIGN_MASK_F_22_42)

// construct float 2242
f2242_t new_f2242(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float64)
// construct float 2242
f2242_t new_f2242_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 2242
f2242_t new_f2242_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 2242
f2242_t new_f2242_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 2242
int64_t exp_f2242(f2242_t a);
// significand part of float 2242
int64_t sig_f2242(f2242_t a);
// add float 2242
f2242_t add_f2242(f2242_t a, f2242_t b);
// subtract float 2242
f2242_t sub_f2242(f2242_t a, f2242_t b);
// negate float 2242
f2242_t neg_f2242(f2242_t a);
// multiply float 2242
f2242_t mul_f2242(f2242_t a, f2242_t b);
// divide float 2242
f2242_t div_f2242(f2242_t a, f2242_t b);
// equals float 2242
bool equ_f2242(f2242_t a, f2242_t b);
// compare float 2242
int com_f2242(f2242_t a, f2242_t b);

#endif // C_FLOAT_22_42_H

