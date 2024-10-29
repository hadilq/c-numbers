#ifndef C_FLOAT_03_29_H
#define C_FLOAT_03_29_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_03_29 3
#define EXPONENT_BITS_F_03_29 06
#define BITS_F_03_29 SIGNIFICAND_BITS_F_03_29 + EXPONENT_BITS_F_03_29

#define C_FLOAT_03_29_DEBUG true

typedef uint32_t f0329_t;

#define SIGNIFICAND_MASK_F_03_29 ((1UL << SIGNIFICAND_BITS_F_03_29) - 1)
#define SIGNIFICAND_2_MASK_F_03_29 ((1ULL << 2 * SIGNIFICAND_BITS_F_03_29) - 1)
#define EXPONENT_MASK_F_03_29 (((1UL << EXPONENT_BITS_F_03_29) - 1) << SIGNIFICAND_BITS_F_03_29)
#define SIGNIFICAND_SIGN_MASK_F_03_29 (1UL << (SIGNIFICAND_BITS_F_03_29 - 1))
#define EXPONENT_SIGN_MASK_F_03_29 (1UL << (EXPONENT_BITS_F_03_29 - 1))
#define BITS_SIGN_MASK_F_03_29 (1UL << (BITS_F_03_29 - 1))

#define MAX_VALUE_F_03_29 (((1U << (EXPONENT_BITS_F_03_29 - 2)) - 1) << SIGNIFICAND_BITS_F_03_29) | ((1U << (SIGNIFICAND_BITS_F_03_29 - 2)) - 1)
#define MIN_VALUE_F_03_29 (((1U << (EXPONENT_BITS_F_03_29 - 2)) - 1) << SIGNIFICAND_BITS_F_03_29) | (SIGNIFICAND_SIGN_MASK_F_03_29)

// construct float 0329
f0329_t new_f0329(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if __is_identifier(_Float32)
// construct float 0329
f0329_t new_f0329_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if __is_identifier(_Float16)
// construct float 0329
f0329_t new_f0329_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 0329
int32_t exp_f0329(f0329_t a);
// significand part of float 0329
int32_t sig_f0329(f0329_t a);
// add float 0329
f0329_t add_f0329(f0329_t a, f0329_t b);
// subtract float 0329
f0329_t sub_f0329(f0329_t a, f0329_t b);
// negate float 0329
f0329_t neg_f0329(f0329_t a);
// multiply float 0329
f0329_t mul_f0329(f0329_t a, f0329_t b);
// divide float 0329
f0329_t div_f0329(f0329_t a, f0329_t b);
// equals float 0329
bool equ_f0329(f0329_t a, f0329_t b);
// compare float 0329
int com_f0329(f0329_t a, f0329_t b);

#endif // C_FLOAT_03_29_H

