#ifndef C_FLOAT_46_18_H
#define C_FLOAT_46_18_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_46_18 46
#define EXPONENT_BITS_F_46_18 18
#define BITS_F_46_18 SIGNIFICAND_BITS_F_46_18 + EXPONENT_BITS_F_46_18

#define C_FLOAT_46_18_DEBUG true

typedef uint64_t f4618_t;

#define SIGNIFICAND_MASK_F_46_18 ((1ULL << SIGNIFICAND_BITS_F_46_18) - 1)
#define SIGNIFICAND_2_MASK_F_46_18 (((__uint128_t)1ULL << 2 * SIGNIFICAND_BITS_F_46_18) - 1)
#define EXPONENT_MASK_F_46_18 (((1ULL << EXPONENT_BITS_F_46_18) - 1) << SIGNIFICAND_BITS_F_46_18)
#define SIGNIFICAND_SIGN_MASK_F_46_18 (1ULL << (SIGNIFICAND_BITS_F_46_18 - 1))
#define EXPONENT_SIGN_MASK_F_46_18 (1ULL << (EXPONENT_BITS_F_46_18 - 1))
#define BITS_SIGN_MASK_F_46_18 (1ULL << (BITS_F_46_18 - 1))

#define MAX_VALUE_F_46_18 (((1ULL << (EXPONENT_BITS_F_46_18 - 2)) - 1) << SIGNIFICAND_BITS_F_46_18) | ((1ULL << (SIGNIFICAND_BITS_F_46_18 - 2)) - 1)
#define MIN_VALUE_F_46_18 (((1ULL << (EXPONENT_BITS_F_46_18 - 2)) - 1) << SIGNIFICAND_BITS_F_46_18) | (SIGNIFICAND_SIGN_MASK_F_46_18)

// construct float 4618
f4618_t new_f4618(int64_t exp, int64_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float64)
// construct float 4618
f4618_t new_f4618_from_float64(_Float64 f);
    #define FLOAT64_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 4618
f4618_t new_f4618_from_float32(_Float32 f);
    #define FLOAT32_BUILTIN
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 4618
f4618_t new_f4618_from_float16(_Float16 f);
    #define FLOAT16_BUILTIN
  #endif
#endif
// exponent part of float 4618
int64_t exp_f4618(f4618_t a);
// significand part of float 4618
int64_t sig_f4618(f4618_t a);
// add float 4618
f4618_t add_f4618(f4618_t a, f4618_t b);
// subtract float 4618
f4618_t sub_f4618(f4618_t a, f4618_t b);
// negate float 4618
f4618_t neg_f4618(f4618_t a);
// multiply float 4618
f4618_t mul_f4618(f4618_t a, f4618_t b);
// divide float 4618
f4618_t div_f4618(f4618_t a, f4618_t b);
// equals float 4618
bool equ_f4618(f4618_t a, f4618_t b);
// compare float 4618
int com_f4618(f4618_t a, f4618_t b);

#endif // C_FLOAT_46_18_H

