#ifndef C_FLOAT_22_10_H
#define C_FLOAT_22_10_H

#include "bits/floatn-common.h"
#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_F_22_10 22
#define EXPONENT_BITS_F_22_10 06
#define BITS_F_22_10 SIGNIFICAND_BITS_F_22_10 + EXPONENT_BITS_F_22_10

#define C_FLOAT_22_10_DEBUG true

typedef uint32_t f2210_t;

#define SIGNIFICAND_MASK_F_22_10 ((1UL << SIGNIFICAND_BITS_F_22_10) - 1)
#define SIGNIFICAND_2_MASK_F_22_10 ((1ULL << 2 * SIGNIFICAND_BITS_F_22_10) - 1)
#define EXPONENT_MASK_F_22_10 (((1UL << EXPONENT_BITS_F_22_10) - 1) << SIGNIFICAND_BITS_F_22_10)
#define SIGNIFICAND_SIGN_MASK_F_22_10 (1UL << (SIGNIFICAND_BITS_F_22_10 - 1))
#define EXPONENT_SIGN_MASK_F_22_10 (1UL << (EXPONENT_BITS_F_22_10 - 1))
#define BITS_SIGN_MASK_F_22_10 (1UL << (BITS_F_22_10 - 1))

#define MAX_VALUE_F_22_10 (((1U << (EXPONENT_BITS_F_22_10 - 2)) - 1) << SIGNIFICAND_BITS_F_22_10) | ((1U << (SIGNIFICAND_BITS_F_22_10 - 2)) - 1)
#define MIN_VALUE_F_22_10 (((1U << (EXPONENT_BITS_F_22_10 - 2)) - 1) << SIGNIFICAND_BITS_F_22_10) | (SIGNIFICAND_SIGN_MASK_F_22_10)

// construct float 2210
f2210_t new_f2210(int32_t exp, int32_t sig);

#ifdef __is_identifier
  #if !__is_identifier(_Float32)
// construct float 2210
f2210_t new_f2210_from_float32(_Float32 f);
  #endif
#endif

#ifdef __is_identifier
  #if !__is_identifier(_Float16)
// construct float 2210
f2210_t new_f2210_from_float16(_Float16 f);
  #endif
#endif

// exponent part of float 2210
int32_t exp_f2210(f2210_t a);
// significand part of float 2210
int32_t sig_f2210(f2210_t a);
// add float 2210
f2210_t add_f2210(f2210_t a, f2210_t b);
// subtract float 2210
f2210_t sub_f2210(f2210_t a, f2210_t b);
// negate float 2210
f2210_t neg_f2210(f2210_t a);
// multiply float 2210
f2210_t mul_f2210(f2210_t a, f2210_t b);
// divide float 2210
f2210_t div_f2210(f2210_t a, f2210_t b);
// equals float 2210
bool equ_f2210(f2210_t a, f2210_t b);
// compare float 2210
int com_f2210(f2210_t a, f2210_t b);

#endif // C_FLOAT_22_10_H

